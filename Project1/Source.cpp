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
	cout << "message: " << hex << message << endl;
	Integer m = Integer((const byte *)message.data(), message.size());
	cout << "message: " << hex << m << endl;
	m = Test.EncryptionByKey(Public, m);
	cout << "encrypted message: " << hex << m << endl;
	Test.DencryptionByKey(Private, m);
	cout << "decrypted message: " << hex << m << endl;

	size_t req = m.MinEncodedSize();
	string recovered;
	recovered.resize(req);
	m.Encode((byte *)recovered.data(), recovered.size());

	cout << "recovered: " << recovered << endl;

	//assert(message == fact);


	system("pause");
	return 0;
}
