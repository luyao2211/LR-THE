// fenbuceshi.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	////参与方的数目(数据所有者+研究者)
	//int participant = 4;
	////数据维数(特征+标签)
	//int col = 50;
	////读取加密参数
	//EncryptionParameters parms(scheme_type::BFV);
	//ifstream in1("d:\\360Downloads\\医院1\\fvparms", ios::in | ios::binary);
	//parms = parms.Load(in1);
	//in1.close();
	//auto context = SEALContext::Create(parms);
	////读取公钥并合成
	//PublicKey *public_key = new PublicKey[participant];
	//string pkdir = "D:\\360Downloads\\医院1\\pk_";
	//for (int i = 0; i < participant; i++)
	//{
	//	ifstream in3(pkdir + to_string(i), ios::in | ios::binary);
	//	public_key[i].load(context, in3);
	//	in3.close();
	//}
	//Encryptor encryptor(context, public_key[participant - 1]);
	//for (int i = 0; i < participant - 1; i++)
	//{
	//	encryptor.pkadd(public_key[i]);
	//}
	////同态加密下逻辑回归1：初始化模型参数
	//BatchEncoder batch_encoder(context);
	//uint64_t *w = new uint64_t[10 * col]{ 0 };
	////将数据分为十折
	//vector<uint64_t> fold;
	//for (int i = 0; i < parms.poly_modulus_degree(); i++)
	//{
	//	fold.push_back(i / 1639);
	//}
	////梯度下降变量定义
	//vector<uint64_t> *encode_w = new vector<uint64_t>[col];
	//Plaintext plain_matrix;
	//Ciphertext *encrypted_w = new Ciphertext[col];
	////迭代5 * 9次
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 9; j++)
	//	{
	//		//研究者加密模型参数并上传至中心平台
	//		for (int k = 0; k < col; k++)
	//		{
	//			encode_w[k].clear();
	//			encode_w[k].shrink_to_fit();
	//		}
	//		for (int k = 0; k < fold.size(); k++)
	//		{
	//			for (int kk = 0; kk < col; kk++)
	//			{
	//				encode_w[kk].push_back(w[((fold[k] + j + 1) % 10) * col + kk]);
	//			}
	//		}
	//		for (int k = 0; k < col; k++)
	//		{
	//			batch_encoder.encode(encode_w[k], plain_matrix);
	//			encryptor.encrypt(plain_matrix, encrypted_w[k]);
	//			ofstream out("d:\\360Downloads\\医院1\\encryptedW_" + to_string(k), ios::out | ios::binary);
	//			encrypted_w[k].save(out);
	//		}
	//	}
	//}
	
	////参与方的数目(数据所有者+研究者)
	//int participant = 4;
	////数据维数(特征+标签)
	//int col = 10;
	////读取加密参数
	//EncryptionParameters parms(scheme_type::BFV);
	//ifstream in1("d:\\360Downloads\\医院1\\fvparms", ios::in | ios::binary);
	//parms = parms.Load(in1);
	//in1.close();
	//auto context = SEALContext::Create(parms);
	////读取之前生成的rlk
	//RelinKeys relin_keys;
	//string rlkdir = "D:\\360Downloads\\医院1\\rlk_";
	//ifstream in5(rlkdir, ios::in | ios::binary);
	//relin_keys.load(context, in5);
	//in5.close();
	////读取待研究数据
	//string reencdir = "D:\\360Downloads\\医院1\\encrypteddata";
	//Ciphertext *encrypted_matrix = new Ciphertext[col * (participant - 1)];
	//for (int i = 0; i < participant - 1; i++)
	//{
	//	for (int j = 0; j < col; j++)
	//	{
	//		ifstream in4(reencdir + to_string(i) + "_" + to_string(j % 10), ios::in | ios::binary);
	//		encrypted_matrix[i * col + j].load(context, in4);
	//		in4.close();
	//	}
	//}
	////读取加密参数
	//string enpdir = "D:\\360Downloads\\医院1\\encryptedW_";
	//Ciphertext *encrypted_w = new Ciphertext[col];
	//for (int i = 0; i < col; i++)
	//{
	//	ifstream in5(enpdir + to_string(i), ios::in | ios::binary);
	//	encrypted_w[i].load(context, in5);
	//	in5.close();
	//}
	////梯度下降变量定义
	//Ciphertext *wx = new Ciphertext[participant - 1];
	//Evaluator evaluator(context);
	//Ciphertext *wx3 = new Ciphertext[participant - 1];
	//Plaintext changshuxiang(parms.poly_modulus_degree());
	//changshuxiang.data()[0] = 313871655918;
	//Ciphertext *gra = new Ciphertext[col * (participant - 1)];
	//Plaintext yicixiang(parms.poly_modulus_degree());
	//yicixiang.data()[0] = 94236826;
	//Plaintext labelxiang(parms.poly_modulus_degree());
	//labelxiang.data()[0] = 1125272161368101;
	////迭代5 * 9次
	//for (int i = 0; i < 2; i++)
	//{
	//	if (i == 1)
	//	{
	//		cout << "first" << endl;
	//	}
	//	for (int j = 0; j < 9; j++)
	//	{
	//		//中心平台计算wx = w0x0 + ... + w8x8 + w9
	//		Ciphertext midresult;
	//		for (int k = 0; k < participant - 1; k++)
	//		{
	//			wx[k] = encrypted_w[col - 1];
	//			for (int kk = 0; kk < col - 1; kk++)
	//			{
	//				evaluator.multiply(encrypted_w[kk], encrypted_matrix[k * col + kk], midresult);
	//				evaluator.relinearize_inplace(midresult, relin_keys);
	//				evaluator.add_inplace(wx[k], midresult);
	//			}
	//		}
	//		//中心平台计算sigmoid和梯度
	//		for (int k = 0; k < participant - 1; k++)
	//		{
	//			evaluator.square(wx[k], wx3[k]);
	//			evaluator.relinearize_inplace(wx3[k], relin_keys);
	//			evaluator.multiply_inplace(wx3[k], wx[k]);
	//			evaluator.relinearize_inplace(wx3[k], relin_keys);
	//			evaluator.negate_inplace(wx3[k]);

	//			evaluator.multiply_plain(encrypted_matrix[k * col + col - 1], labelxiang, gra[k * col + col - 1]);
	//			evaluator.add_inplace(gra[k * col + col - 1], wx3[k]);
	//			evaluator.multiply_plain_inplace(wx[k], yicixiang);
	//			evaluator.add_inplace(gra[k * col + col - 1], wx[k]);
	//			evaluator.add_plain_inplace(gra[k * col + col - 1], changshuxiang);
	//			for (int kk = 0; kk < col - 1; kk++)
	//			{
	//				evaluator.multiply(encrypted_matrix[k * col + kk], gra[k * col + col - 1], gra[k * col + kk]);
	//				evaluator.relinearize_inplace(gra[k * col + kk], relin_keys);
	//			}
	//		}
	//		//中心平台梯度求和
	//		for (int k = 0; k < col; k++)
	//		{
	//			int kk = 1;
	//			while (kk < participant - 1)
	//			{
	//				evaluator.add_inplace(gra[k], gra[col * kk + k]);
	//				kk++;
	//			}
	//			//evaluator.mod_switch_to_inplace(gra[k], context_data->parms().parms_id());
	//		}
	//	}
	//}
	
	////参与方的数目(数据所有者+研究者)
	//int participant = 4;
	////数据维数(特征+标签)
	//int col = 50;
	////读取加密参数
	//EncryptionParameters parms(scheme_type::BFV);
	//ifstream in1("d:\\360Downloads\\医院1\\fvparms", ios::in | ios::binary);
	//parms = parms.Load(in1);
	//in1.close();
	//auto context = SEALContext::Create(parms);
	////读取私钥
	//SecretKey *secret_key = new SecretKey[participant];
	//string skdir = "D:\\360Downloads\\医院1\\sk_";
	//for (int i = 0; i < 2; i++)
	//{
	//	ifstream in2(skdir + to_string(i), ios::in | ios::binary);
	//	secret_key[i].load(context, in2);
	//	in2.close();
	//}
	////读取梯度
	//auto context_data = context->context_data();
	//for (int i = 0; i < 5; i++)
	//{
	//	context_data = context_data->next_context_data();
	//}
	//Evaluator evaluator(context);
	//string reencdir = "D:\\360Downloads\\医院1\\encrypteddata0_";
	//Ciphertext *gra = new Ciphertext[col];
	//for (int i = 0; i < col; i++)
	//{
	//	ifstream in4(reencdir + to_string(i % 10), ios::in | ios::binary);
	//	gra[i].load(context, in4);
	//	in4.close();
	//	evaluator.mod_switch_to_inplace(gra[i], context_data->parms().parms_id());
	//}
	////将数据分为十折
	//vector<uint64_t> fold;
	//for (int i = 0; i < parms.poly_modulus_degree(); i++)
	//{
	//	fold.push_back(i / 1639);
	//}
	////同态加密下逻辑回归1：初始化模型参数
	//BatchEncoder batch_encoder(context);
	//uint64_t *w = new uint64_t[10 * col]{ 0 };
	////梯度下降变量定义
	//Plaintext *result_tidu = new Plaintext[col];
	//double *deltaw = new double[col]();
	//uint64_t Xpod_result;
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 9; j++)
	//	{
	//		//数据所有者进行部分解密
	//		Decryptor decryptorD(context, secret_key[0]);
	//		for (int k = 0; k < col; k++)
	//		{
	//			decryptorD.partialdecrypt(gra[k]);
	//		}
	//		//研究者完全解密
	//		Decryptor decryptor(context, secret_key[1]);
	//		vector<uint64_t> *pod_result = new vector<uint64_t>[col];
	//		for (int k = 0; k < col; k++)
	//		{
	//			decryptor.decrypt(gra[k], result_tidu[k]);
	//			batch_encoder.decode(result_tidu[k], pod_result[k]);
	//		}
	//		//分成十折进行验证
	//		for (int k = 0; k < 10; k++)
	//		{
	//			vector<uint64_t> X;
	//			for (int kk = 0; kk < fold.size(); kk++)
	//			{
	//				if (fold[kk] == (k - j + 9) % 10)
	//				{
	//					X.push_back(1);
	//				}
	//				else
	//				{
	//					X.push_back(0);
	//				}
	//			}
	//			for (int kk = 0; kk < col; kk++)
	//			{
	//				deltaw[kk] = 0;
	//				for (int kkk = 0; kkk < parms.poly_modulus_degree(); kkk++)
	//				{
	//					Xpod_result = X[kkk] * pod_result[kk][kkk];
	//					if (Xpod_result > 562949952339968)
	//					{
	//						if ((k - j + 9) % 10 != 9)
	//						{
	//							deltaw[kk] += ((long long)Xpod_result - 1125899904679937) * 0.81562 * 1000 / (512000000000 * 1639 * 10 * (participant - 1));
	//						}
	//						else
	//						{
	//							deltaw[kk] += ((long long)Xpod_result - 1125899904679937) * 0.81562 * 1000 / (512000000000 * 1633 * 10 * (participant - 1));
	//						}
	//					}
	//					else
	//					{
	//						if ((k - j + 9) % 10 != 9)
	//						{
	//							deltaw[kk] += Xpod_result * 0.81562 * 1000 / (512000000000 * 1639 * 10 * (participant - 1));
	//						}
	//						else
	//						{
	//							deltaw[kk] += Xpod_result * 0.81562 * 1000 / (512000000000 * 1633 * 10 * (participant - 1));
	//						}
	//					}
	//				}
	//				w[k * col + kk] -= round(deltaw[kk]);
	//				if (w[k * col + kk] > 9223372036854775807)
	//				{
	//					w[k * col + kk] += 1125899904679937;
	//				}
	//				else if (w[k * col + kk] > 1125899904679936)
	//				{
	//					w[k * col + kk] -= 1125899904679937;
	//				}
	//			}
	//		}
	//	}
	//}

	////参与方的数目(数据所有者+研究者)
	//int participant = 4;
	////数据维数(特征+标签)
	//int col = 50;
	////读取加密参数
	//EncryptionParameters parms(scheme_type::BFV);
	//ifstream in1("d:\\360Downloads\\医院1\\fvparms", ios::in | ios::binary);
	//parms = parms.Load(in1);
	//in1.close();
	//auto context = SEALContext::Create(parms);
	////读取公钥并合成
	//PublicKey *public_key = new PublicKey[participant];
	//string pkdir = "D:\\360Downloads\\医院1\\pk_";
	//for (int i = 0; i < participant; i++)
	//{
	//	ifstream in3(pkdir + to_string(i), ios::in | ios::binary);
	//	public_key[i].load(context, in3);
	//	in3.close();
	//}
	//Encryptor encryptor(context, public_key[participant - 1]);
	//for (int i = 0; i < participant - 1; i++)
	//{
	//	encryptor.pkadd(public_key[i]);
	//}
	////同态加密下逻辑回归1：初始化模型参数
	//uint64_t *w = new uint64_t[10 * col]{ 0 };
	////梯度下降变量定义
	//Ciphertext *encrypted_w = new Ciphertext[col];
	////10折交叉验证
	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < col; j++)
	//	{
	//		Plaintext plainw(parms.poly_modulus_degree());
	//		plainw.data()[0] = w[i * col + j];
	//		encryptor.encrypt(plainw, encrypted_w[j]);
	//	}
	//}

	////参与方的数目(数据所有者+研究者)
	//int participant = 4;
	////数据维数(特征+标签)
	//int col = 50;
	////读取加密参数
	//EncryptionParameters parms(scheme_type::BFV);
	//ifstream in1("d:\\360Downloads\\医院1\\fvparms", ios::in | ios::binary);
	//parms = parms.Load(in1);
	//in1.close();
	//auto context = SEALContext::Create(parms);
	////读取待研究数据
	//string reencdir = "D:\\360Downloads\\医院1\\encrypteddata";
	//Ciphertext *encrypted_matrix = new Ciphertext[col * (participant - 1)];
	//for (int i = 0; i < participant - 1; i++)
	//{
	//	for (int j = 0; j < col; j++)
	//	{
	//		ifstream in4(reencdir + to_string(i) + "_" + to_string(j % 10), ios::in | ios::binary);
	//		encrypted_matrix[i * col + j].load(context, in4);
	//		in4.close();
	//	}
	//}
	////读取加密参数
	//Ciphertext *encrypted_w = new Ciphertext[col];
	//for (int i = 0; i < col; i++)
	//{
	//	ifstream in4(reencdir + to_string(0) + "_" + to_string(i % 10), ios::in | ios::binary);
	//	encrypted_w[i].load(context, in4);
	//	in4.close();
	//}
	////读取之前生成的rlk
	//RelinKeys relin_keys;
	//string rlkdir = "D:\\360Downloads\\医院1\\rlk_";
	//ifstream in5(rlkdir, ios::in | ios::binary);
	//relin_keys.load(context, in5);
	//in5.close();
	////梯度下降变量定义
	//Ciphertext *wx = new Ciphertext[participant - 1];
	//Evaluator evaluator(context);
	//Ciphertext *wx3 = new Ciphertext[participant - 1];
	//Plaintext changshuxiang(parms.poly_modulus_degree());
	//changshuxiang.data()[0] = 313871655918;
	//Plaintext yicixiang(parms.poly_modulus_degree());
	//yicixiang.data()[0] = 94236826;
	////10折交叉验证
	//for (int i = 0; i < 10; i++)
	//{
	//	//n家data owner
	//	for (int j = 0; j < participant - 1; j++)
	//	{
	//		//计算wx = w0x0 + ... + w7x7 + w8
	//		wx[j] = encrypted_w[col - 1];
	//		Ciphertext midresult;
	//		for (int k = 0; k < col - 1; k++)
	//		{
	//			evaluator.multiply(encrypted_w[k], encrypted_matrix[j * col + k], midresult);
	//			evaluator.relinearize_inplace(midresult, relin_keys);
	//			evaluator.add_inplace(wx[j], midresult);
	//		}
	//		//计算sigmoid
	//		evaluator.square(wx[j], wx3[j]);
	//		evaluator.relinearize_inplace(wx3[j], relin_keys);
	//		evaluator.multiply_inplace(wx3[j], wx[j]);
	//		evaluator.relinearize_inplace(wx3[j], relin_keys);
	//		evaluator.negate_inplace(wx3[j]);
	//		evaluator.multiply_plain_inplace(wx[j], yicixiang);
	//		evaluator.add_inplace(wx3[j], wx[j]);
	//		evaluator.add_plain_inplace(wx3[j], changshuxiang);
	//	}
	//}

	////参与方的数目(数据所有者+研究者)
	//int participant = 21;
	////读取加密参数
	//EncryptionParameters parms(scheme_type::BFV);
	//ifstream in1("d:\\360Downloads\\医院1\\fvparms", ios::in | ios::binary);
	//parms = parms.Load(in1);
	//in1.close();
	//auto context = SEALContext::Create(parms);
	////读取私钥
	//SecretKey *secret_key = new SecretKey[participant];
	//string skdir = "D:\\360Downloads\\医院1\\sk_";
	//for (int i = 0; i < 2; i++)
	//{
	//	ifstream in2(skdir + to_string(i), ios::in | ios::binary);
	//	secret_key[i].load(context, in2);
	//	in2.close();
	//}
	////读取加密参数
	//string reencdir = "D:\\360Downloads\\医院1\\encrypteddata";
	//Ciphertext *wx3 = new Ciphertext[participant - 1];
	//for (int i = 0; i < participant - 1; i++)
	//{
	//	ifstream in4(reencdir + to_string(0) + "_" + to_string(i % 10), ios::in | ios::binary);
	//	wx3[i].load(context, in4);
	//	in4.close();
	//}
	////模型评估
	//double *sigmoid = new double[16384];
	//BatchEncoder batch_encoder(context);
	////10折交叉验证
	//for (int i = 0; i < 10; i++)
	//{
	//	//n家data owner
	//	for (int j = 0; j < participant - 1; j++)
	//	{
	//		//数据所有者进行部分解密
	//		Decryptor decryptorD(context, secret_key[0]);
	//		decryptorD.partialdecrypt(wx3[j]);
	//		//研究者完全解密
	//		Decryptor decryptor(context, secret_key[1]);
	//		Plaintext plain_result;
	//		vector<uint64_t> pod_result;
	//		decryptor.decrypt(wx3[j], plain_result);
	//		batch_encoder.decode(plain_result, pod_result);
	//		for (int k = 0; k < parms.poly_modulus_degree(); k++)
	//		{
	//			if (pod_result[k] > 562949952339968)
	//			{
	//				sigmoid[k] = ((long long)pod_result[k] - 1125899904679937) * 0.81562 / 512000000000;
	//			}
	//			else
	//			{
	//				sigmoid[k] = pod_result[k] * 0.81562 / 512000000000;
	//			}
	//		}
	//	}
	//}

	//参与方的数目(数据所有者+研究者)
	int participant = 21;
	//读取加密参数
	EncryptionParameters parms(scheme_type::BFV);
	ifstream in1("d:\\360Downloads\\医院1\\fvparms", ios::in | ios::binary);
	parms = parms.Load(in1);
	in1.close();
	auto context = SEALContext::Create(parms);
	//读取待研究数据
	string reencdir = "D:\\360Downloads\\医院1\\encrypteddata";
	Ciphertext *encrypted_matrix = new Ciphertext[participant - 1];
	for (int i = 0; i < participant - 1; i++)
	{
		ifstream in4(reencdir + to_string(i) + "_" + to_string(9), ios::in | ios::binary);
		encrypted_matrix[i].load(context, in4);
		in4.close();
	}
	//读取私钥
	SecretKey *secret_key = new SecretKey[participant];
	string skdir = "D:\\360Downloads\\医院1\\sk_";
	for (int i = 0; i < 2; i++)
	{
		ifstream in2(skdir + to_string(i), ios::in | ios::binary);
		secret_key[i].load(context, in2);
		in2.close();
	}
	//模型评估
	double *sigmoid = new double[16384];
	for (int i = 0; i < 16384; i++)
	{
		sigmoid[i] = rand() * 1.12 - 0.06;
	}
	Plaintext plain_matrix;
	BatchEncoder batch_encoder(context);
	Evaluator evaluator(context);
	Ciphertext *miwenTP = new Ciphertext[participant - 1];
	Ciphertext *miwenFP = new Ciphertext[participant - 1];
	Plaintext fuyi(parms.poly_modulus_degree());
	fuyi.data()[0] = 1125899904679936;
	//10折交叉验证
	for (int i = 0; i < 2; i++)
	{
		if (i == 1)
		{
			cout << "first" << endl;
		}
		//计算各个阈值下的4率
		for (double k = -0.06; k < 1.07; k = k + 0.0112)
		{
			for (int j = 0; j < participant - 1; j++)
			{
				//得到预测阳性的数目和预测阴性的数目（包括噪声）
				vector<uint64_t> Prediction;
				for (int kk = 0; kk < parms.poly_modulus_degree(); kk++)
				{
					if (sigmoid[kk] > k)
					{
						Prediction.push_back(1);
					}
					else
					{
						Prediction.push_back(0);
					}
				}
				batch_encoder.encode(Prediction, plain_matrix);
				//得到密文TP & FN
				evaluator.multiply(encrypted_matrix[j], encrypted_matrix[j], miwenTP[j]);
				evaluator.multiply_plain_inplace(miwenTP[j], plain_matrix);
				//得到密文FP & TN
				Ciphertext midresult;
				evaluator.add_plain(encrypted_matrix[j], fuyi, midresult);
				evaluator.negate_inplace(midresult);
				evaluator.multiply(midresult, encrypted_matrix[j], miwenFP[j]);
				evaluator.multiply_plain_inplace(miwenFP[j], plain_matrix);
			}
			//求和
			int j = 1;
			while (j < participant - 1)
			{
				evaluator.add_inplace(miwenTP[0], miwenTP[j]);
				evaluator.add_inplace(miwenFP[0], miwenFP[j]);
				j++;
			}
			//数据所有者进行部分解密
			Decryptor decryptorD(context, secret_key[0]);
			decryptorD.partialdecrypt(miwenTP[0]);
			decryptorD.partialdecrypt(miwenFP[0]);
			//研究者完全解密
			Decryptor decryptor(context, secret_key[1]);
			Plaintext plain_result1, plain_result2;
			vector<uint64_t> pod_result1, pod_result2;
			decryptor.decrypt(miwenTP[0], plain_result1);
			decryptor.decrypt(miwenFP[0], plain_result2);
			batch_encoder.decode(plain_result1, pod_result1);
			batch_encoder.decode(plain_result2, pod_result2);
		}
	}

	std::cout << "end" << endl;
}