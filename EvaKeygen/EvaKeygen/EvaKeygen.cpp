// EvaKeygen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "seal/seal.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace seal;

int main()
{
	EncryptionParameters parms(scheme_type::BFV);
	parms.set_poly_modulus_degree(16384);
	parms.set_coeff_modulus({ 
		DefaultParams::small_mods_30bit(0),
		DefaultParams::small_mods_30bit(1),
		DefaultParams::small_mods_30bit(2),
		DefaultParams::small_mods_30bit(3),
		DefaultParams::small_mods_30bit(4),
		DefaultParams::small_mods_30bit(5),
		DefaultParams::small_mods_30bit(6),
		DefaultParams::small_mods_30bit(7),
		DefaultParams::small_mods_30bit(8),
		DefaultParams::small_mods_30bit(9),
	});
	parms.set_plain_modulus(112500000001);
	auto context = SEALContext::Create(parms);
	KeyGenerator keygen(context);
	SecretKey sec_key = keygen.secret_key();
	PublicKey pub_key = keygen.public_key();
	RelinKeys relin_key = keygen.relin_keys(DefaultParams::dbc_max());

	//EncryptionParameters parms(scheme_type::BFV);
	//ifstream in1("d:\\360Downloads\\医院1\\fvparms", ios::in | ios::binary);
	//parms = parms.Load(in1);
	//in1.close();
	//auto context = SEALContext::Create(parms);
	//auto qualifiers = context->context_data()->qualifiers();
	//cout << "Batching enabled: " << boolalpha << qualifiers.using_batching << endl;
	////1 researcher + 2 data owner
	//int participant = 4;
	////读取私钥
	//SecretKey *secret_keys = new SecretKey[participant];
	//string skdir = "D:\\360Downloads\\医院1\\sk_";
	//for (int i = 0; i < participant; i++)
	//{
	//	ifstream in2(skdir + to_string(i), ios::in | ios::binary);
	//	secret_keys[i].load(context, in2);
	//	in2.close();
	//}
	////生成联合relin_key
	//KeyGenerator keygen(context, secret_keys[participant - 1]);
	//for (int i = 0; i < participant - 1; i++)
	//{
	//	keygen.skadd(secret_keys[i]);
	//}
	//string rlkdir = "D:\\360Downloads\\医院1\\rlk_";
	//ofstream out1(rlkdir, ios::out | ios::binary);
	//KeyGenerator rekeygen(context, keygen.secret_key());
	//RelinKeys relin_keys = rekeygen.relin_keys(DefaultParams::dbc_max());
	//relin_keys.save(out1);
	//out1.close();

	//测试
	/*ifstream in3("D:\\360Downloads\\医院1\\encrypteddata0_0", ios::in | ios::binary);
	Ciphertext enceshi;
	enceshi.load(context, in3);
	in3.close();
	Evaluator evaluator(context);
	evaluator.square_inplace(enceshi);
	evaluator.relinearize_inplace(enceshi, relin_keys);
	Decryptor decryptor(context, keygen.secret_key());
	Plaintext plain;
	decryptor.decrypt(enceshi, plain);
	BatchEncoder encoder(context);
	vector<uint64_t> result;
	encoder.decode(plain, result);*/

	//delete[] secret_keys;
}