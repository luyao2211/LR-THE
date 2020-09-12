// EncryptionDataOwner.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	parms.set_poly_modulus_degree(32768);
	parms.set_coeff_modulus(DefaultParams::coeff_modulus_192(32768));
	parms.set_plain_modulus(34359410689);
	vector<uint64_t> pod_matrix;
	for (int i = 0; i < parms.poly_modulus_degree(); i++)
	{
		pod_matrix.push_back((uint64_t)(rand() + rand() % 16 * pow(2,31)));
	}
	auto context = SEALContext::Create(parms);
	KeyGenerator keygen(context);
	PublicKey pub_key = keygen.public_key();
	SecretKey sec_key = keygen.secret_key();
	Evaluator evaluator(context);
	BatchEncoder batch_encoder(context);
	Plaintext plain_matrix;
	batch_encoder.encode(pod_matrix, plain_matrix);
	Ciphertext encrypted_matrix;
	Encryptor encryptor(context, pub_key);
	encryptor.encrypt(plain_matrix, encrypted_matrix);
	Decryptor decryptor(context, sec_key);
	cout << decryptor.invariant_noise_budget(encrypted_matrix) << endl;
	evaluator.multiply_plain_inplace(encrypted_matrix, plain_matrix);
	cout << decryptor.invariant_noise_budget(encrypted_matrix) << endl;
	evaluator.multiply_plain_inplace(encrypted_matrix, plain_matrix);
	cout << decryptor.invariant_noise_budget(encrypted_matrix) << endl;

	//ifstream in1("d:\\360Downloads\\医院1\\fvparms", ios::in | ios::binary);
	//parms = parms.Load(in1);
	//in1.close();
	//auto context = SEALContext::Create(parms);
	//auto qualifiers = context->context_data()->qualifiers();
	//cout << "Batching enabled: " << boolalpha << qualifiers.using_batching << endl;
	//KeyGenerator keygen(context);
	//BatchEncoder batch_encoder(context);
	////假设一共有10家dataowner和一家researcher
	//string pkdir = "D:\\360Downloads\\医院1\\pk_";
	//string datadir = "D:\\360Downloads\\医院1\\data_";
	//string encdir = "D:\\360Downloads\\医院1\\encrypteddata";
	//int *mingwen = new int[parms.poly_modulus_degree() * 10];
	////参与方的数目(数据所有者+研究者)
	//int participant = 4;
	////读取公钥并合成
	//PublicKey *public_key = new PublicKey[participant];
	//for (int i = 0; i < participant; i++)
	//{
	//	ifstream in2(pkdir + to_string(i), ios::in | ios::binary);
	//	public_key[i].load(context, in2);
	//	in2.close();
	//}
	//Encryptor encryptor(context, public_key[participant - 1]);
	//for (int i = 0; i < participant - 1; i++)
	//{
	//	encryptor.pkadd(public_key[i]);
	//}
	//Evaluator evaluator(context);
	////加密数据
	//for (int i = 0; i < participant - 1; i++)
	//{
	//	ifstream in3(datadir + to_string(i % 2), ios::in | ios::binary);
	//	for (int j = 0; j < parms.poly_modulus_degree() * 10; j++)
	//	{
	//		in3.read((char*)&mingwen[j], sizeof(int));
	//	}
	//	in3.close();
	//	for (int j = 0; j < 10; j++)
	//	{
	//		vector<uint64_t> pod_matrix;
	//		for (int k = 0; k < parms.poly_modulus_degree(); k++)
	//		{
	//			pod_matrix.push_back(mingwen[k * 10 + j]);
	//		}
	//		Plaintext plain_matrix;
	//		batch_encoder.encode(pod_matrix, plain_matrix);
	//		Ciphertext encrypted_matrix;
	//		encryptor.encrypt(plain_matrix, encrypted_matrix);
	//		ofstream out(encdir + to_string(i) + "_" + to_string(j), ios::out | ios::binary);
	//		encrypted_matrix.save(out);
	//		out.close();
	//	}
	//}
	//delete[] mingwen;
	//delete[] public_key;
}