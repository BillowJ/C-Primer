// file_finder.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <istream>
#include <algorithm>
#include <sstream>
using namespace std;

struct Query_Result
{
public:
	friend ostream& print(ostream&, const Query_Result&);

public:
	using LineNo = vector<string>::size_type;
	Query_Result(const string& s, shared_ptr<set<LineNo>> set, shared_ptr<vector<string>> v)
		: word(s), nos(set), input(v) { }

private:
	string word;
	using LineNo = vector<string>::size_type;
	shared_ptr<vector<string>> input;
	shared_ptr<set<LineNo>> nos;//行号
};

struct TextQuery {
public:
	using LineNo = vector<string>::size_type;
	TextQuery(ifstream& ifs);//构造函数
	Query_Result query(const string&) const;

private:
	shared_ptr<vector<string>> input;//用来保存文件内容 内容被QueryResult贡献 所以使用shared_ptr
	map <string, shared_ptr<set<LineNo>>> result;
};

TextQuery::TextQuery(ifstream& ifs) : input(new vector<string>) {
	LineNo lineNo{ 0 };
	for (string line; getline(ifs, line); ++lineNo) {
		input->push_back(line);
		istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear()) {
			std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);//一句话中 逐个读入单词 并移除标点符号（example,） 然后写入到word里面进行处理
			auto& nos = result[word];
			if (!nos) nos.reset(new set<LineNo>);//若不存在 reset释放原有内存 并使nos指向一个new的LineNo类型的set
			nos->insert(lineNo);//若存在单词 则将其行号插入map<string, shared_ptr<set<LineNo>>> result[nos]的set中,注意 set是单词出现的行号集合 不重复
		}
	}
}

Query_Result TextQuery::query(const string& str) const {
	static shared_ptr<set<LineNo>> nodate(new set<LineNo>);
	auto found = result.find(str);
	if (found == result.end())//没找到该字符串
		return Query_Result(str, nodate, input);
	else
		return Query_Result(str, found->second, input);//found->second : set<LineNo> 返回Query_Result 类型的结果 
}

std::ostream& print(ostream& out, const Query_Result& qr) {
	out << qr.word << " occurs" << qr.nos->size()
		<< (qr.nos->size() > 1 ? "times" : "time") << endl;
	for (auto i : *qr.nos) {
		out << "\t(line " << i + 1 << ")" << qr.input->at(i) << endl;//at（i）定位到固定行号内容
	}
	return out;
}

void runQueries(std::ifstream& infile)
{
	if (!infile) throw runtime_error("error! the file not exist!");
	TextQuery tq(infile);
	while (true) {
		std::cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(std::cin >> s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main()
{
	
	ifstream file("D:/Dir_C++/Test12/Project12.3/test.txt");
	runQueries(file);

}

