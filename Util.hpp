#include <iostream>
#include <string>
#include <memory>
#include <json/json.h>
#include "mongoose.h"

using namespace std;

class Util{
	public:
		static string mgStrToString(struct mg_str*ms)
		{
			string str="";
			for(unsigned int i=0;i< ms->len;i++)
				str.push_back(ms->p[i]);
			return str;
		}

		static bool GetNameAndPasswd(string info,string &name,string &passwd)
		{
			bool result;
			JSONCPP_STRING errs;
			Json::Value root;
			Json::CharReaderBuilder rb;
			unique_ptr<Json::CharReader>const cr(rb.newCharReader());
			result =cr->parse(info.data(),info.data()+info.size(),&root,&errs);
			if(!result||!errs.empty())
			{
				cerr<<"parse error"<< endl;
				return false;
			}
			name =root["name"].asString();
			passwd=root["passwd"].asString();
			return true;
		}
};
