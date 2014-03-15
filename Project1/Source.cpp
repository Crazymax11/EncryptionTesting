//#include "stdafx.h" 
#include <iostream> 
#include <dll.h>
#include <cryptlib.h>
#include "RawRSATest.h"
#include <time.h>
#include <ctime>

USING_NAMESPACE(CryptoPP)
using namespace std;

int main()
{
	//есть проблема с супердлинными сообщениями
	string message = "mama mila ramu smert neizbejna boga net";
	AutoSeededRandomPool  _ASRP;

	std::list <CryptoTest*> Tests;

	//Задаем алгоритмы :3
	Tests.push_front(new RawRSATest(512));
	Tests.push_front(new RawRSATest(1024));
	Tests.push_front(new RawRSATest(2048));
	Tests.push_front(new RawRSATest(4096));

	Integer randomMessage;
	byte randomBytes[40];

	// Тестирование всех алгоритмов
	for each (CryptoTest* Test in Tests)
	{
		Test->PrintInfo();
		_ASRP.GenerateBlock(randomBytes, 40);
		randomMessage.Decode(randomBytes, 40);
		Test->PrintTest(randomMessage);
		cout << "--------" << endl;
	}
	
	int count = 10000;
	// 10к итераций
	for each (CryptoTest* Test in Tests)
	{
		Test->PrintInfo();
		std::clock_t t1 = clock();
		for (int i = 0; i < count; i++)
		{
			_ASRP.GenerateBlock(randomBytes, 40);
			randomMessage.Decode(randomBytes, 40);
			randomMessage = Test->DecryptionByKey(Public, randomMessage);
			randomMessage = Test->EncryptionByKey(Private, randomMessage);
		}
		float ElapsedTime = float(clock() - t1) / (1000 / CLOCKS_PER_SEC);
		cout << "Elapsed Time (ms) : " << ElapsedTime << endl;
		cout << "Time for one Crypt (ms) : " << ElapsedTime / count << endl;
		cout << "--------" << endl;

	}

	system("pause");
	return 0;
}
