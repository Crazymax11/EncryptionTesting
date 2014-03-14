#include <dll.h>
#include <cryptlib.h>

USING_NAMESPACE(CryptoPP)

enum Keys
{
	Public = 1,
	Private =2
};

class RawRSATest
{
public:
	RawRSATest(const int keySize)
	{
		_privateKey.Initialize(_rnd, keySize);
		_publicKey = *(new RSA::PublicKey(_privateKey));

		_keySize = keySize;

		//ValidateKeys();
		
	}
	~RawRSATest()
	{
		delete &_publicKey;
	}
	Integer EncryptionByKey(Keys _key, Integer& message) const
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
	}

	Integer DencryptionByKey(Keys _key, Integer& message) 
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
	}
private:

AutoSeededRandomPool _rnd;
RSA::PrivateKey _privateKey;
RSA::PublicKey _publicKey;
int _keySize;



	/*
	private bool ValidateKeys()
	{
		bool result = true;
		if (!_privateKey.Validate(_rnd, _keySize))
		{
			throw runtime_error("Rsa private key validation failed");
			result = false;
		}

		if (!_publicKey.Validate(_rnd, _keySize))
		{
			throw runtime_error("Rsa public key validation failed");
			result = false;
		}
			
		return result;
	}
	*/
};