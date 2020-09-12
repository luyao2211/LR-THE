// KeygenCenter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "seal/seal.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace seal;
using namespace std;

int main()
{
	/*EncryptionParameters parms(scheme_type::BFV);
	parms.set_poly_modulus_degree(16384);
	parms.set_coeff_modulus(DefaultParams::coeff_modulus_128(16384));
	parms.set_plain_modulus(1125899904679937);
	auto context = SEALContext::Create(parms);
	auto qualifiers = context->context_data()->qualifiers();
	cout << "Batching enabled: " << boolalpha << qualifiers.using_batching << endl;
	bool flag = true;
	KeyGenerator keygen(context, flag);
	uint64_t *pk1 = keygen.public_key_1();
	ofstream out1("d:\\360Downloads\\医院1\\fvparms", ios::out | ios::binary);
	parms.Save(parms, out1);
	out1.close();
	ofstream out2("d:\\360Downloads\\医院1\\pk1", ios::out | ios::binary);
	size_t count = parms.poly_modulus_degree() * parms.coeff_modulus().capacity();
	for (size_t i = 0; i < count; i++)
	{
		out2.write((char*)&pk1[i], sizeof(uint64_t));
	}
	out2.close();*/

	EncryptionParameters parms(scheme_type::CKKS);
	parms.set_poly_modulus_degree(16384);
	parms.set_coeff_modulus({
		DefaultParams::small_mods_40bit(0),
		DefaultParams::small_mods_40bit(1),
		DefaultParams::small_mods_40bit(2),
		DefaultParams::small_mods_40bit(3),
		DefaultParams::small_mods_40bit(4),
		DefaultParams::small_mods_40bit(5),
		DefaultParams::small_mods_40bit(6),
		DefaultParams::small_mods_40bit(7),
		DefaultParams::small_mods_40bit(8),
		DefaultParams::small_mods_40bit(9) });
	auto context = SEALContext::Create(parms);
	KeyGenerator keygen(context);
	auto public_key = keygen.public_key();
	auto secret_key = keygen.secret_key();
	auto relin_keys = keygen.relin_keys(DefaultParams::dbc_max());
	Encryptor encryptor(context, public_key);
	Evaluator evaluator(context);
	Decryptor decryptor(context, secret_key);
	CKKSEncoder encoder(context);
	size_t slot_count = encoder.slot_count();
	vector<double> input;
	for (int i = 0; i < slot_count; i++)
	{
		input.push_back(1);
	}
	Plaintext plain;
	double scale = pow(2.0, 40);
	encoder.encode(input, scale, plain);
	Ciphertext encrypted;
	encryptor.encrypt(plain, encrypted);
	evaluator.multiply_inplace(encrypted, encrypted);
	evaluator.relinearize_inplace(encrypted, relin_keys);
	
	scale = pow(2.0, 80);
	encoder.encode(input, scale, plain);
	Ciphertext encrypted1;
	encryptor.encrypt(plain, encrypted1);
	evaluator.multiply_inplace(encrypted, encrypted1);
	//evaluator.multiply_plain_inplace(encrypted, plain);
	decryptor.decrypt(encrypted, plain);
	encoder.decode(plain, input);
	for (int i = 0; i < slot_count; i++)
	{
		input[i] -= 1;
	}
}