/*--------------------------------------------------------------------------------------|
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。					|
																						|
比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：								|
																						|
L   C   I   R																			|
E T O E S I I G																			|
E   D   H   N																			|
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。	|
																						|
请你实现这个将字符串进行指定行数变换的函数：											|
																						|
string convert(string s, int numRows);													|
示例 1:																					|
																						|
输入: s = "LEETCODEISHIRING", numRows = 3												|
输出: "LCIRETOESIIGEDHN"																|
示例 2:																					|
																						|
输入: s = "LEETCODEISHIRING", numRows = 4												|
输出: "LDREOEIIECIHNTSG"																|
解释:																					|
																						|
L     D     R																			|
E   O E   I I																			|
E C   I H   N																			|
T     S     G																			|
																						|
来源：力扣（LeetCode）																	|
链接：https://leetcode-cn.com/problems/zigzag-conversion								|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。					|
---------------------------------------------------------------------------------------*/

/*	按照顺序进行填写输出
*	执行用时：32 ms, 在所有 C++ 提交中击败了30.80%的用户
*	内存消耗：10.5 MB, 在所有 C++ 提交中击败了57.71%的用户
*/

#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows)
{
	int length = s.size();

	if (numRows == 1)
	{
		return s;
	}

	int flag = 1;
	string result;

	vector<string> result_rows(min(numRows, length));						/*	向量可以实现多维字符串	*/

	int row = 0;

	for (int i = 0; i < length; i++)
	{
		result_rows[row] += s[i];
		if (row == 0 || row == numRows - 1)
		{
			flag = !flag;
		}
		row += flag ? -1 : 1;
	}

	//for (int j = 0; j < numRows; j++)										/*	如果用这种方法，前面要排除掉numRows比length大的情况，不然在j==length的时候会没有值，因为上面的循环并不能对result_rows[length]以后的字符串赋值	*/
	//{
	//	result += result_rows[j];
	//}

	for (string p:result_rows)												/*	用元素遍历的方法可以少些一种条件判断	*/
	{																		
		result += p;
	}

	return result;
}



int main()
{
	string s = "A";
	int numRows = 2;

	string result;
	result = convert(s, numRows);

	//
	//int length = s.size();

	//if (numRows > length)
	//{
	//	result =  s;
	//}

	//int flag = 1;
	////string result;

	//vector<string> result_rows(min(numRows, length));						/*	向量可以实现多维字符串	*/

	//int row = 0;

	//for (int i = 0; i < length; i++)
	//{
	//	result_rows[row] += s[i];
	//	if (row == 0 || row == numRows - 1)
	//	{
	//		flag = !flag;
	//	}
	//	row += flag ? -1 : 1;
	//}

	//for (int j = 0; j < numRows; j++)
	//{
	//	result += result_rows[j];
	//}
	//

	cout << result << endl;
}