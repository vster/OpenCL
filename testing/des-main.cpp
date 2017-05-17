#include <iostream>
#include <iomanip>
#include <opencl/des.h>
#include <opencl/desx.h>

#define KL 8
#define BS 8

using namespace std;
using namespace OpenCL;

void output_hex(byte data[],int len)
{
    for (int i = 0; i < len; i++)
        cout << hex << setfill('0') << setw(2)
             << (int)data[i] << " ";
    cout << endl;
}

byte kzu1[KL] = {0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF};
byte to1[BS] =  {0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xE7};
byte tc1[BS] =  {0xC9,0x57,0x44,0x25,0x6A,0x5E,0xD3,0x1D};

byte kzu2[KL] = {0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x80};
byte to2[BS] =  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte tc2[BS] =  {0x9C,0xC6,0x2D,0xF4,0x3B,0x6E,0xED,0x74};

int main(void)
{
    OpenCL::DES d1;
    byte key[KL];
    byte data[BS];
    byte datac[BS];
    byte datad[BS];
    int i;

    // for (i = 0; i < KL; i++)
    //    key[i] = i;
    memcpy(key,kzu2,KL);

    cout << "DES" << endl;
    cout << "KL = " << KL << endl;
    cout << "BS = " << BS << endl;
    cout << "Key" << endl;
    output_hex(key, KL);

    // for (i = 0; i < BS; i++)
    //     data[i] = i + 0x30;
    memcpy(data,to2,BS);

    cout << "Initial data" << endl;
    output_hex(data, BS);

    d1.set_key(key, KL);

    d1.encrypt(data, datac);

    cout << "Encrypted data" << endl;
    output_hex(datac, BS);

    if (memcmp(datac,tc2,BS))
        cout << "Encrypt test failed." << endl;
    else
        cout << "Encrypt test is OK." << endl;

    d1.decrypt(datac, datad);

    cout  << "Decrypted data" << endl;
    output_hex(datad, BS);
}
