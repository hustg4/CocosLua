#ifndef __DES_H 
#define __DES_H 

//#define DES					sss_xxx0
//#define encrypt3			sss_xxx1
//#define decrypt3			sss_xxx2
//#define encrypt				sss_xxx3
//#define decrypt				sss_xxx4
//#define encrypt3_file		sss_xxx5
//#define decrypt3_file		sss_xxx6
//#define extend				sss_xxx7
//#define _encrypt_no_extend	sss_xxx8
//#define des					sss_xxx9
//#define des_block			sss_xxx10
//#define deskey				sss_xxx11
//#define usekey				sss_xxx12
//#define cookey				sss_xxx13

class DES {

public:
	int encrypt3(unsigned char key[24], unsigned char* data, int size);
	int decrypt3(unsigned char key[24], unsigned char* data, int dataSize, int* size);

	int encrypt(unsigned char key[8], unsigned char* data, int size);
	int decrypt(unsigned char key[8], unsigned char* in, int blocks, int* size = 0);

	//加密文件
	int encrypt3_file(unsigned char key[24], const char *plainFile, const char *cipherFile);
	//解密文件
	int decrypt3_file(unsigned char key[24], const char *cipherFile, const char *plainFile);

	int extend(int size) {
		return (size / 8 + 1) * 8;
	};

private:
	int _encrypt_no_extend(unsigned char key[8], unsigned char* data, int size);
    
    int _decrypt_no_padding(unsigned char key[8], unsigned char* in, int blocks, int* size = 0);
    
    int lengthOfPlaintext(unsigned char* data,int size);
    
	void des(unsigned char* in, unsigned char* out, int blocks);
	void des_block(unsigned char* in, unsigned char* out);

private:
	unsigned long KnL[32];
	enum Mode {
		ENCRYPT, DECRYPT
	};
	void deskey(unsigned char key[8], Mode md);
	void usekey(unsigned long *);
	void cookey(unsigned long *);

private:
	void scrunch(unsigned char *, unsigned long *);
	void unscrun(unsigned long *, unsigned char *);
	void desfunc(unsigned long *, unsigned long *);

private:
	static unsigned char Df_Key[24];
	static unsigned short bytebit[8];
	static unsigned long bigbyte[24];
	static unsigned char pc1[56];
	static unsigned char totrot[16];
	static unsigned char pc2[48];
	static unsigned long SP1[64];
	static unsigned long SP2[64];
	static unsigned long SP3[64];
	static unsigned long SP4[64];
	static unsigned long SP5[64];
	static unsigned long SP6[64];
	static unsigned long SP7[64];
	static unsigned long SP8[64];

};

#endif 
