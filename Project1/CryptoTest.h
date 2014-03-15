#include <dll.h>
#include <cryptlib.h>

USING_NAMESPACE(CryptoPP)
using namespace std;

enum Keys
{
	Public = 1,
	Private = 2
};

class CryptoTest
{
public:
	CryptoTest(){};
	~CryptoTest(){};
	virtual Integer EncryptionByKey(Keys, Integer&)  = 0;
	virtual Integer DecryptionByKey(Keys, Integer&)  = 0;
	virtual void PrintInfo() const = 0;
	void PrintTest(Integer& m) 
	{
		cout << "message: " << hex << m << endl;
		m = EncryptionByKey(Public, m);
		cout << "encrypted message: " << hex << m << endl;
		m = DecryptionByKey(Private, m);
		cout << "decrypted message: " << hex << m << endl;
	}

private:
	

};