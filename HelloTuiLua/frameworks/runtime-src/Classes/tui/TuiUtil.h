/************************************************************************
The MIT License(MIT)

Copyright(c) 2014 Lingjijian [B-y]

342854406@qq.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
************************************************************************/
#ifndef __TUI_UTIL_H__
#define __TUI_UTIL_H__

#include "cocos2d.h"
#include "TuiMacros.h"

NS_TUI_BEGIN

using namespace std;
/**
 * @brief the tool
 *
 */
class TuiUtil{
public:
	/**
	 * @brief use name to create the animation
	 * 
	 * @param name
	 * @param delay 
	 * @param iLoops Whether loop
	 * @return Animation
	 */
	static Animation* createAnimWithName(const char* name,float delay,unsigned int iLoops);
	/**
	 * @brief use name and Play frames to create the animation
	 * 
	 * @param name
	 * @param iNum frame number
	 * @param delay 
	 * @param iLoops Whether loop
	 * @return Animation
	 */
	static Animation* createAnimWithNameAndNum(const char* name,int iNum, float delay,unsigned int iLoops);
	/*
	* @brief replace all string in actual ,such as => replace_all(string("12212"),"12","21") => 22211
	*
	* @param str text
	* @param old_value
	* @param new_value
	* @return string
	*/
	static string replace_all_actual(string str, const string& old_value, const string& new_value);
	/*
	* @brief replace all string ,such as => replace_all(string("12212"),"12","21") => 21221
	*
	* @param str text
	* @param old_value
	* @param new_value
	* @return string
	*/
	static string replace_all(string str, const string& old_value, const string& new_value);
    /*
     * @brief split string ,such as => split(string("ff_a"),"_") => ["ff","a"]
     *
     * @param str text
     * @param delim
     * @return string
     */
    static vector< string > split(const string& s,const string& delim);

	static vector< string > separateUtf8(const std::string& inStr);

	static bool isChinese(const std::string& s);

protected:
private:
};


NS_TUI_END

#endif