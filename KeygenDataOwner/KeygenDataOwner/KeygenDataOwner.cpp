// KeygenDataOwner.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	ifstream in1("d:\\360Downloads\\医院1\\fvparms", ios::in | ios::binary);
	parms = parms.Load(in1);
	in1.close();
	size_t count = parms.poly_modulus_degree() * parms.coeff_modulus().capacity();
	uint64_t *pk1 = new uint64_t[count];
	ifstream in2("d:\\360Downloads\\医院1\\pk1", ios::in | ios::binary);
	for (size_t i = 0; i < count; i++)
	{
		in2.read((char*)&pk1[i], sizeof(uint64_t));
	}
	in2.close();
	auto context = SEALContext::Create(parms);
	auto qualifiers = context->context_data()->qualifiers();
	cout << "Batching enabled: " << boolalpha << qualifiers.using_batching << endl;
	//假设一共有10家dataowner和一家researcher
	string skdir = "D:\\360Downloads\\医院1\\sk_";
	string pkdir = "D:\\360Downloads\\医院1\\pk_";
	for (int i = 0; i < 4; i++)
	{
		KeyGenerator keygen(context, pk1);
		auto public_key = keygen.public_key();
		auto secret_key = keygen.secret_key();
		ofstream out1(skdir + to_string(i), ios::out | ios::binary);
		secret_key.save(out1);
		out1.close();
		ofstream out2(pkdir + to_string(i), ios::out | ios::binary);
		public_key.save(out2);
		out2.close();
	}
	delete[] pk1;
}