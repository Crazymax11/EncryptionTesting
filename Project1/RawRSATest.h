#include "CryptoTest.h"

USING_NAMESPACE(CryptoPP)
using namespace std;

class RawRSATest : public CryptoTest
{
public:
	RawRSATest(const int keySize) : CryptoTest()
	{
		_privateKey.Initialize(_rnd, keySize);
		_publicKey = *(new RSA::PublicKey(_privateKey));

		_keySize = keySize;
	}

	~RawRSATest()
	{
		delete &_publicKey;
	}

	virtual Integer EncryptionByKey(Keys _key, Integer& message) 
	{
		   switch (_key)
		   {
		   case Keys::Public:
			   message = _publicKey.ApplyFunction(message);
			   break;
		   case Keys::Private:
			   message = _privateKey.ApplyFunction(message);
			   break;
		   }
		   return message;
	};

	Integer DecryptionByKey(Keys _key, Integer& message) 
	{
		   switch (_key)
		   {
		   case Keys::Public:
			   // TODO: хз почему не могу декриптить пабликом
			   break;
		   case Keys::Private:
			   message = _privateKey.CalculateInverse(_rnd, message);
			   break;
		   }
		   return message;
	};

	void PrintInfo() const
	{
		cout << "this is RSA Raw on Crypto++" << endl << "Key size is " << _keySize << endl;
	};


private:

	AutoSeededRandomPool _rnd;
	RSA::PrivateKey _privateKey;
	RSA::PublicKey _publicKey;
	int _keySize;
};