//#include "stdafx.h" 
#include <iostream> 
#include <dll.h>
#include <cryptlib.h>
#include "RawRSATest.h"

USING_NAMESPACE(CryptoPP)
using namespace std;

int main()
{
	Integer fact(2);
	for (int i = 3; i <= 50; ++i)
		fact *= i;
	cout << "Calculating 100! = " << fact;

	cout << "\n\nSearching first prime above 1000000000 : ";
	Integer p("1000000000");
	while (!IsPrime(p)) ++p;
	cout << p << endl;

	//RSA Test
	RawRSATest Test(512);
	//есть проблема с супердлинными сообщениями
	string message = "mama mila ramu smert neizbejna boga net";
	Integer m = Integer((const byte *)message.data(), message.size());
	Test.PrintTest(m);
	

	cout << "RawRSATest" << endl;
	//10к раз шифрование
	cout << "Encryption" << endl;



	system("pause");
	return 0;
}
