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

/*	计算通式横向直接存取
*	执行用时：16 ms, 在所有 C++ 提交中击败了83.98%的用户
*	内存消耗：8 MB, 在所有 C++ 提交中击败了93.07%的用户
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

	string result;

	int cycleround = 2 * numRows - 2;

	for (int i = 0; i < numRows; i++)														/*	循环的设计是提高算法速度和节约空间的关键	*/
	{
		for (int j = 0; i + j < length; j += cycleround)									/*	在第i行，利用j不断增加来改变读取的值，j_0 = 0，j_i = i*cycleround	*/
		{
			result += s[i + j];
			if (i != 0 && i != numRows - 1 && j + cycleround - i < length)					/*	由于还未进行到下一个j，此时可以将j_i与j_i+1之间的值找出加入result，对应位置为s[j_i+cycleround-i]	*/
			{
				result += s[j + cycleround - i];
			}
		}
	}

	return result;
}

int main()
{
	string s = "LEETCODEISHIRING";
	int numRows = 3;

	string result;
	result = convert(s, numRows);

	cout << result << endl;
}