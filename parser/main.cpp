#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

enum Packet_type{
  Null ,
  Audio_Clock_Regeneration,
  Audio_Sample,
  General_Control,
  ACP_Packet,
  ISRC1_Packet,
  ISRC2_Packet,
  One_Bit_Audio_Sample_Packet,
  DST_Audio_Packet,
  High_Bitrate_Audio_Stream_Packet,
  Gamut_Metadata_Packet,
  InfoFrame_Packet

};
const char *arr_type[]= {"Null",
                         "Audio Clock Regeneration",
                         "Audio Sample",
                         "General Control",
                         "ACP Packet",
                         "ISRC1 Packet",
                         "ISRC2 Packet",
                         "One Bit Audio Sample Packet",
                         "DST Audio Packet",
                         "High Bitrate (HBR) Audio Stream Packet (IEC 61937)",
                         "Gamut Metadata Packet",
                         "InfoFrame Packet"
                        };
int main() {
    int HB0=0;
    int HB1=0;
    int HB2=0;
    int SB0=0;
    int SB1=0;
    int SB2=0;
    int SB3=0;
    int SB4=0;
    int SB5=0;
    int SB6=0;
    int PB0=0;
    int PB1=0;
    int PB2=0;
    int PB3=0;
    int PB4=0;
    int PB5=0;
    int PB6=0;
    int PB7=0;
    int PB8=0;
    int PB9=0;
    int PB10=0;
    int PB11=0;
    int PB12=0;
    int PB13=0;
    int PB14=0;
    int PB15=0;
    int PB16=0;
    int PB17=0;
    int PB18=0;
    int PB19=0;
    int PB20=0;
    int PB21=0;
    int PB22=0;
    int PB23=0;
    int PB24=0;
    int PB25=0;
    int PB26=0;
    int PB27=0;



    ifstream in("E:\\test_files\\parser1.txt",ios::binary|ios::in);
      in.read((char*)&HB0,sizeof HB0);
      in.read((char*)&HB1,sizeof HB1);
      in.read((char*)&HB2,sizeof HB2);
      in.read((char*)&SB0,sizeof SB0);
      in.read((char*)&SB1,sizeof SB1);
      in.read((char*)&SB2,sizeof SB2);
      in.read((char*)&SB3,sizeof SB3);
      in.read((char*)&SB4,sizeof SB4);
      in.read((char*)&SB5,sizeof SB5);
      in.read((char*)&SB6,sizeof SB6);
      in.read((char*)&PB0,sizeof PB0);
      in.read((char*)&PB1,sizeof PB1);
      in.read((char*)&PB2,sizeof PB2);
      in.read((char*)&PB3,sizeof PB3);
      in.read((char*)&PB4,sizeof PB4);
      in.read((char*)&PB5,sizeof PB5);
      in.read((char*)&PB6,sizeof PB6);
      in.read((char*)&PB7,sizeof PB7);
      in.read((char*)&PB8,sizeof PB8);
      in.read((char*)&PB9,sizeof PB9);
      in.read((char*)&PB10,sizeof PB10);
      in.read((char*)&PB11,sizeof PB11);
      in.read((char*)&PB12,sizeof PB12);
      in.read((char*)&PB13,sizeof PB13);
      in.read((char*)&PB14,sizeof PB14);
      in.read((char*)&PB15,sizeof PB15);
      in.read((char*)&PB16,sizeof PB16);
      in.read((char*)&PB17,sizeof PB17);
      in.read((char*)&PB18,sizeof PB18);
      in.read((char*)&PB19,sizeof PB19);
      in.read((char*)&PB20,sizeof PB20);
      in.read((char*)&PB21,sizeof PB21);
      in.read((char*)&PB22,sizeof PB22);
      in.read((char*)&PB23,sizeof PB23);
      in.read((char*)&PB24,sizeof PB24);
      in.read((char*)&PB25,sizeof PB25);
      in.read((char*)&PB26,sizeof PB26);
      in.read((char*)&PB27,sizeof PB27);
    in.close();
    //int k = HB0-129;
    Packet_type pflag;



    switch (HB0) {
    case 0x00:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x01:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if ((HB1 == 0) && (HB2 == 0) && (SB0 == 0)&& ((SB1>>4) == 0)){
            long CTS = (SB1<<16)|(SB2<<8)|SB3;
            long N = (SB4<< 16)|(SB5<<8)|SB6;
            cout<<"CTS: "<< CTS <<endl;
            cout<<"N: "<< N <<endl;
        }
        else{
            cout<<"invalid"<<endl;
        }
        break;
    case 0x02:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if ((HB1>>5) == 0){
              long layout = HB1&0x10;
              long spX = HB1&0xF;
              long sfX = HB2&0xF;
              long B = HB2&(0xF0);
              long L = (SB0<<4)|(SB1<<12)|(SB2<<20);
              long R = (SB3<<4)|(SB4<<12)|(SB5<<20);
              long Vl =(SB6&0x01);
              long Vr =(SB6&0x10);
              long Ul =(SB6&0x02);
              long Ur =(SB6&0x20);
              long Cl =(SB6&0x04);
              long Cr =(SB6&0x40);
              long Pl =(SB6&0x08);
              long Pr =(SB6&0x80);

              cout<<"layout: "<<layout<<endl;
              cout<<"sample_present.spX: "<<spX<<endl;
              cout<<"sample_flat.spX: "<<sfX<<endl;
              cout<<"B: "<<B<<endl;
              cout<<"L: "<<L<<endl;
              cout<<"R: "<<R<<endl;
              cout<<"Vl: "<<Vl<<endl;
              cout<<"Vr: "<<Vr<<endl;
              cout<<"Ul: "<<Ul<<endl;
              cout<<"Ur: "<<Ur<<endl;
              cout<<"Cl: "<<Cl<<endl;
              cout<<"Cr: "<<Cr<<endl;
              cout<<"Pl: "<<Pl<<endl;
              cout<<"Pr: "<<Pr<<endl;
         }
        else{
            cout<<"invalid"<<endl;
        }
        break;
    case 0x03:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
         if ((HB1 == 0) && (HB2 == 0) && ((SB0&0xEE)==0) && ((SB2>>1)==0) && (SB3 == 0) && (SB4 == 0) && (SB5 == 0) && (SB6 == 0)){
             long setAVMUTE = (SB0&0x01);
             long clearAVMUTE = (SB0&0x10);
             long PP = (SB1)&(0xF0);
             long CD = (SB1&0xF);
             long defaultPhase = (SB2&0x01);
             cout<<"Set_AVMUTE: "<<setAVMUTE<<endl;
             cout<<"Clear_AVMUTE: "<<clearAVMUTE<<endl;
             cout<<"PP: "<<PP<<endl;
             cout<<"CD: "<<CD<<endl;
             cout<<"Default_Phase: "<<defaultPhase<<endl;
         }
        break;
    case 0x04:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if (HB2 == 0){
            switch (HB1) {
            case 0x00:
                if ((PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
                cout<<"ACP_Type: Generic Audio"<<endl;}
                break;
            case 0x01:
                if ((PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
                cout<<"ACP_Type: IEC 60958-Identified Audio"<<endl;}
                break;
            case 0x02:
                cout<<"ACP_Type: DVD-Audio"<<endl;
            if ((PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
                    long DATDG = (PB0&0xFF);
                    long CopyP = (PB1&0xC0);
                    long CopyN = (PB1&0x38);
                    long Quality = (PB1&0x06);
                    long Trans = (PB1&0x01);
                    cout<<"DVD-Audio_Type_Dependent_Generation: "<<DATDG<<endl;
                    cout<<"Copy_Permission: "<<CopyP<<endl;
                    cout<<"Copy_Number: "<<CopyN<<endl;
                    cout<<"Quality: "<<Quality<<endl;
                    cout<<"Transaction: "<<Trans<<endl;
                }
                break;
           case 0x03:
                cout<<"ACP_Type: Super Audio CD"<<endl;
                if ((PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
                long CCI = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 | PB6 | PB7 | PB8 | PB9 | PB10 | PB11 | PB12 | PB13 | PB14 | PB15 ;
                cout<<"CCI_1: "<<CCI<<endl;
                }
            default:

                break;
            }

        }
        break;
    case 0x05:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if (((HB1&0x38) == 0) && (HB2==0)) {
            long Cont = (HB1&0x80);
            long Status = (HB1&0x07);
            long Valid =(HB1&0x40);
            cout<<"ISRC_Cont: "<<Cont<<endl;
            cout<<"ISRC_Status: "<<Status<<endl;
            cout<<"ISRC_Valid: "<<Valid<<endl;
            if((PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
                long UEI0 = PB0;
                long UEI1 = PB1;
                long UEI2 = PB2;
                long UEI3 = PB3;
                long UEI4 = PB4;
                long UEI5 = PB5;
                long UEI6 = PB6;
                long UEI7 = PB7;
                long UEI8 = PB8;
                long UEI9 = PB9;
                long UEI10 = PB10;
                long UEI11 = PB11;
                long UEI12 = PB12;
                long UEI13 = PB13;
                long UEI14 = PB14;
                long UEI15 = PB15;
                cout<<"UPC_EAN_ISRC_0"<<UEI0<<endl;
                cout<<"UPC_EAN_ISRC_1"<<UEI1<<endl;
                cout<<"UPC_EAN_ISRC_2"<<UEI2<<endl;
                cout<<"UPC_EAN_ISRC_3"<<UEI3<<endl;
                cout<<"UPC_EAN_ISRC_4"<<UEI4<<endl;
                cout<<"UPC_EAN_ISRC_5"<<UEI5<<endl;
                cout<<"UPC_EAN_ISRC_6"<<UEI6<<endl;
                cout<<"UPC_EAN_ISRC_7"<<UEI7<<endl;
                cout<<"UPC_EAN_ISRC_8"<<UEI8<<endl;
                cout<<"UPC_EAN_ISRC_9"<<UEI9<<endl;
                cout<<"UPC_EAN_ISRC_10"<<UEI10<<endl;
                cout<<"UPC_EAN_ISRC_11"<<UEI11<<endl;
                cout<<"UPC_EAN_ISRC_12"<<UEI12<<endl;
                cout<<"UPC_EAN_ISRC_13"<<UEI13<<endl;
                cout<<"UPC_EAN_ISRC_14"<<UEI14<<endl;
                cout<<"UPC_EAN_ISRC_15"<<UEI15<<endl;
            }
        }
        break;
    case 0x06:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if ((HB1 == 0) && (HB2 == 0) && ((PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0)){
            long UEI16 = PB0;
            long UEI17 = PB1;
            long UEI18 = PB2;
            long UEI19 = PB3;
            long UEI20 = PB4;
            long UEI21 = PB5;
            long UEI22 = PB6;
            long UEI23 = PB7;
            long UEI24 = PB8;
            long UEI25 = PB9;
            long UEI26 = PB10;
            long UEI27 = PB11;
            long UEI28 = PB12;
            long UEI29 = PB13;
            long UEI30 = PB14;
            long UEI31 = PB15;
            cout<<"UPC_EAN_ISRC_16"<<UEI16<<endl;
            cout<<"UPC_EAN_ISRC_17"<<UEI17<<endl;
            cout<<"UPC_EAN_ISRC_18"<<UEI18<<endl;
            cout<<"UPC_EAN_ISRC_19"<<UEI19<<endl;
            cout<<"UPC_EAN_ISRC_20"<<UEI20<<endl;
            cout<<"UPC_EAN_ISRC_21"<<UEI21<<endl;
            cout<<"UPC_EAN_ISRC_22"<<UEI22<<endl;
            cout<<"UPC_EAN_ISRC_23"<<UEI23<<endl;
            cout<<"UPC_EAN_ISRC_24"<<UEI24<<endl;
            cout<<"UPC_EAN_ISRC_25"<<UEI25<<endl;
            cout<<"UPC_EAN_ISRC_26"<<UEI26<<endl;
            cout<<"UPC_EAN_ISRC_27"<<UEI27<<endl;
            cout<<"UPC_EAN_ISRC_28"<<UEI28<<endl;
            cout<<"UPC_EAN_ISRC_29"<<UEI29<<endl;
            cout<<"UPC_EAN_ISRC_30"<<UEI30<<endl;
            cout<<"UPC_EAN_ISRC_31"<<UEI31<<endl;
        }
        break;
    case 0x07:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if (((HB1&0xE0)==0) && ((HB2&0xF0)==0)){
            long layout1 = (HB1&0x10);
            long sp3 = (HB1&0x08);
            long sp2 = (HB1&0x04);
            long sp1 = (HB1&0x02);
            long sp0 = (HB1&0x01);
            long si0 = (HB2&0x01);
            long si1 = (HB2&0x02);
            long si2 = (HB2&0x04);
            long si3 = (HB2&0x08);
            long ChA = (SB0)|(SB1<<8)|(SB2<<16)|(SB6&0xF);
            long ChB = (SB3)|(SB4<<8)|(SB5<<16)|(SB6&0xF);
            cout<<"layout: "<<layout1<<endl;
            cout<<"samples_present.sp0: "<<sp0<<endl;
            cout<<"samples_present.sp1: "<<sp1<<endl;
            cout<<"samples_present.sp2: "<<sp2<<endl;
            cout<<"samples_present.sp3: "<<sp3<<endl;
            cout<<"samples_invalid.sp0: "<<si0<<endl;
            cout<<"samples_invalid.sp1: "<<si1<<endl;
            cout<<"samples_invalid.sp2: "<<si2<<endl;
            cout<<"samples_invalid.sp3: "<<si3<<endl;
            cout<<"ChA: "<<ChA<<endl;
            cout<<"ChB: "<<ChB<<endl;
        }
        break;
    case 0x08:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if (((HB1&0x3E) == 0) && (HB2 == 0)){
            long frames = (HB1&0x80);
            long samplesi = (HB1&0x40);
            long DSTnd = (HB1&0x01);
            long Dx = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
            cout<<"farme_start: "<<frames<<endl;
            cout<<"saqmples_invalid: "<<samplesi<<endl;
            cout<<"DST_normal_double: "<<DSTnd<<endl;
            cout<<"D.X: "<<Dx<<endl;
        }
        break;
    case 0x09:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if ((HB1 == 0) && ((HB2&0xF) == 0)){
            long Bx = (HB2&0xF0);
            cout<<"B.X: "<<Bx<<endl;
    }

        break;
    case 0x0A:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if ((HB2&0x40)==0){
            long nextf = HB1&0x80;
            long nocrnt = HB2&0x80;
            long GBDprof = HB1&0x70;
            long agsn = HB1&0xF;
            long cgsn = HB2&0xF;
            long packetseq = HB2&0x30;
            cout<<"Next_Field: "<<nextf<<endl;
            cout<<"No_Current_GBD: "<<nocrnt<<endl;
            cout<<"GBD_profile: "<<GBDprof<<endl;
            cout<<"Affected_Gamut_Seq_Num: "<<agsn<<endl;
            cout<<"Current_Gamut_Seq_Num: "<<cgsn<<endl;
            cout<<"Packet_Seq: "<<packetseq<<endl;
            switch (GBDprof) {
               case 0:{
                cout<<"P0"<<endl;
                long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                cout<<"GBD: "<<GBD<<endl;}
                break;
               case 0x01:{
                cout<<"P1"<<endl;
                if (packetseq == 0){
                    long GBDLengthH = (PB0);
                    long GBDLengthL = (PB1);
                    long Checksum = (PB2);
                    long GBD = PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                    cout<<"GBD_Length_H: "<<GBDLengthH<<endl;
                    cout<<"GBD_Length_L: "<<GBDLengthL<<endl;
                    cout<<"Checksum: "<<Checksum<<endl;
                    cout<<"GBD: "<<GBD<<endl;
                }

                else {
                    long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                    cout<<"GBD: "<<GBD<<endl;
                }}
                break;
            case 2:{
                cout<<"P2"<<endl;
                if (packetseq == 0){
                    long GBDLengthH = (PB0);
                    long GBDLengthL = (PB1);
                    long Checksum = (PB2);
                    long GBD = PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                    cout<<"GBD_Length_H: "<<GBDLengthH<<endl;
                    cout<<"GBD_Length_L: "<<GBDLengthL<<endl;
                    cout<<"Checksum: "<<Checksum<<endl;
                    cout<<"GBD: "<<GBD<<endl;
                }
                else {
                    long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                    cout<<"GBD: "<<GBD<<endl;
                }}
                break;
            case 3:{
                cout<<"P3"<<endl;
                if (packetseq == 0){
                    long GBDLengthH = (PB0);
                    long GBDLengthL = (PB1);
                    long Checksum = (PB2);
                    long GBD = PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                    cout<<"GBD_Length_H: "<<GBDLengthH<<endl;
                    cout<<"GBD_Length_L: "<<GBDLengthL<<endl;
                    cout<<"Checksum: "<<Checksum<<endl;
                    cout<<"GBD: "<<GBD<<endl;
                }
                else {
                    long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                    cout<<"GBD: "<<GBD<<endl;
                }
                break;}
            default:{
                        cout<<"check spicifications"<<endl;
                break;
            }}

        }
        break;
    case 0x80 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x81 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x82 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x83 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x84 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x85 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    default:
        cerr<<"invalid byte"<<endl;
        break;
    }
    if (((HB0&0x80) !=0) && ((HB2&0xE0) == 0)){
        long IFType = HB0&0x7F;
        switch (IFType) {
        case 0x01:{
            cout<<"InfoFrame Type: Vendor Specific InfoFrame"<<endl;
             long IFVersion = HB1;
             long IFLenght = HB2&0x1F;
             if (IFVersion == 0x01){
                  long IEEE= PB1 | (PB2<<8) | (PB3<<16);
                  long VA = (PB4&0xF0);
                  long VB = (PB4&0xF);
                  long VC = (PB5&0xF0);
                  long VD = (PB5&0xF);
                  long SupAI = (PB6&0x80);
                  long DC48bit = (PB6&0x40);
                  long DC36bit = (PB6&0x20);
                  long DC30bit = (PB6&0x10);
                  long DCY444 = (PB6&0x08);
                  long DVIDUAL = (PB6&0x010);
                  long MAXTMDS = (PB7);
                  long LFP = (PB8&0x80);
                  long ILFP = (PB8&0x40);
                  cout<<"InfoFrame_version: "<<IFVersion<<endl;
                  cout<<"InfoFrame_length: "<<IFLenght<<endl;
                  cout<<"IEEE Registration Identifier: "<<IEEE<<endl;
                  cout<<"A: "<<VA<<endl;
                  cout<<"B: "<<VB<<endl;
                  cout<<"C: "<<VC<<endl;
                  cout<<"D: "<<VD<<endl;
                  cout<<"Supports_AI: "<<SupAI<<endl;
                  cout<<"DC_30bit: "<<DC30bit<<endl;
                  cout<<"DC_36bit: "<<DC36bit<<endl;
                  cout<<"DC_48bit: "<<DC48bit<<endl;
                  cout<<"DC_Y444: "<<DCY444<<endl;
                  cout<<"DVI_Dual: "<<DVIDUAL<<endl;
                  cout<<"Max_TMDS_Clock: "<<MAXTMDS<<endl;
                  cout<<"Latency_Fields_Present: "<<LFP<<endl;
                  cout<<"I_Latency_Fields_Present: "<<ILFP<<endl;
                 }
             if (IFLenght>=9){
                long VideoLatency = PB9;
                cout<<"Video_Latency: "<<VideoLatency<<endl;
                if (IFLenght>=10){
                    long AudioLatency = PB10;
                    cout<<"Audio_Latency: "<<AudioLatency<<endl;
                    if (IFLenght>=11){
                        long InterlacedVideoLatency = PB11;
                        cout<<"Interlaced_Video_Latency: "<<InterlacedVideoLatency<<endl;
                        if (IFLenght>=12){
                            long InterlacedAudioLatency = PB12;
                            cout<<"Interlaced_Audio_Latency: "<<InterlacedAudioLatency<<endl;
                    }
                }
             }
             }
            break;}
        case 0x02:{
            cout<<"InfoFrame Type: AVI InfoFrame"<<endl;
            long IFVersion = HB1;
            if (IFVersion == 0x01){
                 long IFLenght = HB2&0x1F;
                 cout<<"Version: "<<IFVersion<<endl;
                 cout<<"Length: "<<IFLenght<<endl;
                 long Y = (PB1&0x60)>>5;
                 switch (Y) {
                 case 0x00:{
                     cout<<"Y: "<< Y <<" : RGB (default)"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"Y: "<< Y <<" : YCBCR 4:2:2"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"Y: "<< Y <<" : YCBCR 4:4:4"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"Y: "<< Y <<" : *future*"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long A = (PB1&0x10)>>4;
                 switch (A) {
                 case 0x00:{
                     cout<<"A: "<< A <<" : No Active Format Information"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"A: "<< A <<" : Active Format (R3...R0) Information present"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long B = (PB1&0x0C)>>2;
                 switch (B) {
                 case 0x00:{
                     cout<<"B: "<< B <<" : Bar Data not present"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"B: "<< B <<" : Vert. Bar Info present"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"B: "<< B <<" : Horiz. Bar Info present"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"B: "<< B <<" : Vert. and Horiz. Bar Info present"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long S = (PB1&0x03);
                 switch (S) {
                 case 0x00:{
                     cout<<"S: "<< S <<" : No Data"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"S: "<< S <<" : Composed for an overscanned display, where some active pixels and lines at the edges are not displayed."<<endl;
                     break;}
                 case 0x02:{
                     cout<<"S: "<< S <<" : Composed for an underscanned display, where all active pixels & lines are displayed, with or without a border."<<endl;
                     break;}
                 case 0x03:{
                     cout<<"S: "<< S <<" : *future*"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long C = (PB2&0xC0)>>6;
                 switch (C) {
                 case 0x00:{
                     cout<<"C: "<< C <<" : No Data"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"C: "<< C <<" : SMPTE 170M [1]"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"C: "<< C <<" : ITU-R 709 [7]"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"C: "<< C <<" : Extended Colorimetry Information Valid"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long M = (PB2&0x30)>>4;
                 switch (M) {
                 case 0x00:{
                     cout<<"M: "<< M <<" : No Data"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"M: "<< M <<" : 4:3"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"M: "<< M <<" : 16:9"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"M: "<< M <<" : *future*"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long R = (PB2&0x0F);
                 switch (R) {
                 case 0x08:{
                     cout<<"R: "<< R <<" : Same as coded frame aspect ratio"<<endl;
                     break;}
                 case 0x09:{
                     cout<<"R: "<< R <<" : 4:3 (center)"<<endl;
                     break;}
                 case 0x0A:{
                     cout<<"R: "<< R <<" : 16:9 (center)"<<endl;
                     break;}
                 case 0x0B:{
                     cout<<"R: "<< R <<" : 14:9 (center)"<<endl;
                     break;}
                 default:{
                     cout<<"R: "<< R <<" : Varies. See Annex H."<<endl;
                     break;}
                 }
                 long SC = (PB3&0x03);
                 switch (SC) {
                 case 0x00:{
                     cout<<"Non-Uniform Picture Scaling: "<< SC <<" : No Know non-uniform Scaling"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"Non-Uniform Picture Scaling: "<< SC <<" : Picture has been scaled horizontally"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"Non-Uniform Picture Scaling: "<< SC <<" : Picture has been scaled vertically"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"Non-Uniform Picture Scaling: "<< SC <<" : Picture has been scaled horizontally and vertically"<<endl;
                     break;}
                 default:{

                     break;}}
                 long ETB = (PB5&0xFF) | (PB6&0xFF00);
                 long SBB = (PB7&0xFF) | (PB8&0xFF00);
                 long ELB = (PB9&0xFF) | (PB10&0xFF00);
                 long SRB = (PB11&0xFF) | (PB12&0xFF00);
                 cout<<"ETB: "<<ETB<<endl;
                 cout<<"SBB: "<<SBB<<endl;
                 cout<<"ELB: "<<ELB<<endl;
                 cout<<"SRB: "<<SRB<<endl;
            }
            if (IFVersion == 0x02){
                 long IFLenght = HB2&0x1F;
                 cout<<"Version: "<<IFVersion<<endl;
                 cout<<"Length: "<<IFLenght<<endl;
                 long Y = (PB1&0x60)>>5;
                 switch (Y) {
                 case 0x00:{
                     cout<<"Y: "<< Y <<" : RGB (default)"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"Y: "<< Y <<" : YCBCR 4:2:2"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"Y: "<< Y <<" : YCBCR 4:4:4"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"Y: "<< Y <<" : *future*"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long A = (PB1&0x10)>>4;
                 switch (A) {
                 case 0x00:{
                     cout<<"A: "<< A <<" : No Active Format Information"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"A: "<< A <<" : Active Format (R3...R0) Information present"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long B = (PB1&0x0C)>>2;
                 switch (B) {
                 case 0x00:{
                     cout<<"B: "<< B <<" : Bar Data not present"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"B: "<< B <<" : Vert. Bar Info present"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"B: "<< B <<" : Horiz. Bar Info present"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"B: "<< B <<" : Vert. and Horiz. Bar Info present"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long S = (PB1&0x03);
                 switch (S) {
                 case 0x00:{
                     cout<<"S: "<< S <<" : No Data"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"S: "<< S <<" : Composed for an overscanned display, where some active pixels and lines at the edges are not displayed."<<endl;
                     break;}
                 case 0x02:{
                     cout<<"S: "<< S <<" : Composed for an underscanned display, where all active pixels & lines are displayed, with or without a border."<<endl;
                     break;}
                 case 0x03:{
                     cout<<"S: "<< S <<" : *future*"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long C = (PB2&0xC0)>>6;
                 switch (C) {
                 case 0x00:{
                     cout<<"C: "<< C <<" : No Data"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"C: "<< C <<" : SMPTE 170M [1]"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"C: "<< C <<" : ITU-R 709 [7]"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"C: "<< C <<" : Extended Colorimetry Information Valid"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long M = (PB2&0x30)>>4;
                 switch (M) {
                 case 0x00:{
                     cout<<"M: "<< M <<" : No Data"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"M: "<< M <<" : 4:3"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"M: "<< M <<" : 16:9"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"M: "<< M <<" : *future*"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long R = (PB2&0x0F);
                 switch (R) {
                 case 0x08:{
                     cout<<"R: "<< R <<" : Same as coded frame aspect ratio"<<endl;
                     break;}
                 case 0x09:{
                     cout<<"R: "<< R <<" : 4:3 (center)"<<endl;
                     break;}
                 case 0x0A:{
                     cout<<"R: "<< R <<" : 16:9 (center)"<<endl;
                     break;}
                 case 0x0B:{
                     cout<<"R: "<< R <<" : 14:9 (center)"<<endl;
                     break;}
                 default:{
                     cout<<"R: "<< R <<" : Varies. See Annex H."<<endl;
                     break;}
                 }
                 long ITC = (PB3&0x80)>>7;
                 switch (ITC) {
                 case 0x00:{
                     cout<<"IT content: "<< ITC <<" : No Data"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"IT content: "<< ITC <<" : IT content (Byte 5 CN bits valid)"<<endl;
                     break;}
                 default:{

                     break;}
                 }
                 long EC = (PB3&0x70)>>4;
                 switch (EC) {
                 case 0x00:{
                     cout<<"Extended Colorimetry: "<< EC <<" : xvYCC601"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"Extended Colorimetry: "<< EC <<" : xvYCC709"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"Extended Colorimetry: "<< EC <<" : sYCC601"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"Extended Colorimetry: "<< EC <<" : AdobeYCC601"<<endl;
                     break;}
                 case 0x04:{
                     cout<<"Extended Colorimetry: "<< EC <<" : AdobeRGB"<<endl;
                     break;}
                 default:{
                     cout<<"EC: "<< EC <<endl;
                     break;}
                 }
                 long Q = (PB3&0x0C)>>2;
                 switch (Q) {
                 case 0x00:{
                     cout<<"RGB Quanitization Range: "<< Q <<" : Default (depends on video format)"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"RGB Quanitization Range: "<< Q <<" : Limit Range"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"RGB Quanitization Range: "<< Q <<" : Full Range"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"RGB Quanitization Range: "<< Q <<" : Reserved"<<endl;
                     break;}
                 default:{

                     break;}}
                 long SC = (PB3&0x03);
                 switch (SC) {
                 case 0x00:{
                     cout<<"Non-Uniform Picture Scaling: "<< SC <<" : No Know non-uniform Scaling"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"Non-Uniform Picture Scaling: "<< SC <<" : Picture has been scaled horizontally"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"Non-Uniform Picture Scaling: "<< SC <<" : Picture has been scaled vertically"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"Non-Uniform Picture Scaling: "<< SC <<" : Picture has been scaled horizontally and vertically"<<endl;
                     break;}
                 default:{

                     break;}}
                 long VIC = (PB4&0x7F);
                 switch (VIC) {
                 case 1:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"640x480p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 2:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x480p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 3:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x480p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 4:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1280x720p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 5:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080i @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 6:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x480i @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 7:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x480i @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 8:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x240p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 9:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x240p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 10:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x480i @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 to 10 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 11:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x480i @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 to 10 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 12:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x240p @ 59.94/60Hz"<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 to 10 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 13:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x240p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 to 10 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 14:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1440x480p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 to 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 15:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1440x480p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 to 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 16:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 17:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x576p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 18:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x576p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 19:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1280x720p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 20:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080i @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 21:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x576i @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 22:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x576i @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 23:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x288p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 24:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x288p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 25:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x576i @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 to 10 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 26:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x576i @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 to 10 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 27:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x288p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 to 10 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 28:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x288p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 to 10 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 29:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1440x576p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 or 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 30:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1440x576p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1 or 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 31:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 32:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080p @ 23.98/24Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 33:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080p @ 25Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 34:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080p @ 29.98/30Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 35:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x480p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1, 2 or 4 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 36:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x480p @ 59.94/60Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1, 2 or 4 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 37:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x576p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1, 2 or 4 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 38:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"2880x576p @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 1, 2 or 4 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"Yes "<<endl;
                     break;}
                 case 39:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080i (1250) @ 50Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 40:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080i @ 100Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 41:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1280x720p @ 100Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 42:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x576p @ 100Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 43:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x576p @ 100Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     break;}
                 case 44:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x576i @ 100Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 45:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x576i @ 100Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 46:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080i @ 119.88/120Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 47:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1280x720p @ 119.88/120Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 48:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x480p @ 119.88/120Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 49:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x480p @ 119.88/120Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 50:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x480i @ 119.88/120Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 51:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x480i @ 119.88/120Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 52:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x576p @ 200Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 53:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x576p @ 200Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 54:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x576i @ 200Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 55:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x576i @ 200Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 56:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x480p @ 239.76/240Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 57:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720x480p @ 239.76/240Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 58:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x480i @ 239.76/240Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 59:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"720(1440)x480i @ 239.76/240Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"pixel data sent 2 times "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 60:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1280x720p @ 23.97Hz/24Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 61:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1280x720p @ 25Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 62:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1280x720p @ 29.97Hz/30Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 63:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080p @ 119.88Hz/120Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 case 64:{
                     cout<<"VIC: "<< VIC <<endl;
                     cout<<"Video Description: "<<"1920x1080p @ 100Hz "<<endl;
                     cout<<"Valid Pixel Repeat Values: "<<"No Repetition "<<endl;
                     cout<<"AVI w/PR Required: "<<"No "<<endl;
                     break;}
                 default:{
                     cout<<"VIC: "<< VIC <<endl;
                     break;}}
                 long YQ = (PB3&0xC0)>>6;
                 switch (YQ) {
                 case 0x00:{
                     cout<<"YCC Quanitization Range: "<< YQ <<" : Limited Range"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"YCC Quanitization Range: "<< YQ <<" : Full Range"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"YCC Quanitization Range: "<< YQ <<" : Reserved"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"YCC Quanitization Range: "<< YQ <<" : Reserved"<<endl;
                     break;}
                 default:{

                     break;}}
                 long CN = (PB3&0x30)>>4;
                 switch (CN) {
                 case 0x00:{
                     cout<<"IT Content Type: "<< CN <<" : Graphics"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"IT Content Type: "<< CN <<" : Photo"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"IT Content Type: "<< CN <<" : Cinema"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"IT Content Type: "<< CN <<" : Game"<<endl;
                     break;}
                 default:{

                     break;}}
                 long PR = PB4&0x0F;
                 switch (PR) {
                 case 0x00:{
                     cout<<"Pixel Repetition Factor: "<< PR <<" : No Repetition (i.e., pixel date sent once)"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"Pixel Repetition Factor: "<< PR <<" : Pixel data sent 2 times (i.e., repeated once)"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"Pixel Repetition Factor: "<< PR <<" : Pixel data sent 3 times"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"Pixel Repetition Factor: "<< PR <<" : Pixel data sent 4 times"<<endl;
                     break;}
                 case 0x04:{
                     cout<<"Pixel Repetition Factor: "<< PR <<" : Pixel data sent 5 times"<<endl;
                     break;}
                 case 0x05:{
                     cout<<"Pixel Repetition Factor: "<< PR <<" : Pixel data sent 6 times"<<endl;
                     break;}
                 case 0x06:{
                     cout<<"Pixel Repetition Factor: "<< PR <<" : Pixel data sent 7 times"<<endl;
                     break;}
                 case 0x07:{
                     cout<<"Pixel Repetition Factor: "<< PR <<" : Pixel data sent 8 times"<<endl;
                     break;}
                 case 0x08:{
                     cout<<"Pixel Repetition Factor: "<< PR <<" : Pixel data sent 9 times"<<endl;
                     break;}
                 case 0x09:{
                     cout<<"Pixel Repetition Factor: "<< PR <<" : Pixel data sent 10 times"<<endl;
                     break;}
                 default:{
                     cout<<"Pixel Repetition Factor: "<< PR <<" : Reserved"<<endl;
                     break;}
                 }
                 long ETB = (PB5&0xFF) | (PB6&0xFF00);
                 long SBB = (PB7&0xFF) | (PB8&0xFF00);
                 long ELB = (PB9&0xFF) | (PB10&0xFF00);
                 long SRB = (PB11&0xFF) | (PB12&0xFF00);
                 cout<<"ETB: "<<ETB<<endl;
                 cout<<"SBB: "<<SBB<<endl;
                 cout<<"ELB: "<<ELB<<endl;
                 cout<<"SRB: "<<SRB<<endl;

            }
            break;}
        case 0x03:{
            cout<<"InfoFrame Type: Source Product Descriptor InfoFrame"<<endl;
            long IFVersion = HB1;
            long IFLenght = HB2&0x1F;
            if ((IFVersion == 0x01) && (IFLenght == 25)){
                 long VN1 = PB1&0xEF;
                 long VN2 = PB2&0xEF;
                 long VN3 = PB3&0xEF;
                 long VN4 = PB4&0xEF;
                 long VN5 = PB5&0xEF;
                 long VN6 = PB6&0xEF;
                 long VN7 = PB7&0xEF;
                 long VN8 = PB8&0xEF;
                 long PD1 = PB9&0xEF;
                 long PD2 = PB10&0xEF;
                 long PD3 = PB11&0xEF;
                 long PD4 = PB12&0xEF;
                 long PD5 = PB13&0xEF;
                 long PD6 = PB14&0xEF;
                 long PD7 = PB15&0xEF;
                 long PD8 = PB16&0xEF;
                 long PD9 = PB17&0xEF;
                 long PD10 = PB18&0xEF;
                 long PD11 = PB19&0xEF;
                 long PD12 = PB20&0xEF;
                 long PD13 = PB21&0xEF;
                 long PD14 = PB22&0xEF;
                 long PD15 = PB23&0xEF;
                 long PD16 = PB24&0xEF;

                 cout<<"Version: "<<IFVersion<<endl;
                 cout<<"Length: "<<IFLenght<<endl;
                 cout<<"VN1: "<<VN1<<endl;
                 cout<<"VN2: "<<VN2<<endl;
                 cout<<"VN3: "<<VN3<<endl;
                 cout<<"VN4: "<<VN4<<endl;
                 cout<<"VN5: "<<VN5<<endl;
                 cout<<"VN6: "<<VN6<<endl;
                 cout<<"VN7: "<<VN7<<endl;
                 cout<<"VN8: "<<VN8<<endl;
                 cout<<"PD1: "<<PD1<<endl;
                 cout<<"PD2: "<<PD2<<endl;
                 cout<<"PD3: "<<PD3<<endl;
                 cout<<"PD4: "<<PD4<<endl;
                 cout<<"PD5: "<<PD5<<endl;
                 cout<<"PD6: "<<PD6<<endl;
                 cout<<"PD7: "<<PD7<<endl;
                 cout<<"PD8: "<<PD8<<endl;
                 cout<<"PD9: "<<PD9<<endl;
                 cout<<"PD10: "<<PD10<<endl;
                 cout<<"PD11: "<<PD11<<endl;
                 cout<<"PD12: "<<PD12<<endl;
                 cout<<"PD13: "<<PD13<<endl;
                 cout<<"PD14: "<<PD14<<endl;
                 cout<<"PD15: "<<PD15<<endl;
                 cout<<"PD16: "<<PD16<<endl;
                 long SourceINFO = PB25;
                 switch (SourceINFO) {
                 case 0x00:
                     cout<<"Source Information: unknown ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x01:
                     cout<<"Source Information: Digital STB ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x02:
                     cout<<"Source Information: DVD player ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x03:
                     cout<<"Source Information: D-VHS ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x04:
                     cout<<"Source Information: HDD Videorecorder ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x05:
                     cout<<"Source Information: DVC ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x06:
                     cout<<"Source Information: DSC ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x07:
                     cout<<"Source Information: Video CD ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x08:
                     cout<<"Source Information: Game ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x09:
                     cout<<"Source Information: PC general ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x0A:
                     cout<<"Source Information: Blu-Ray Disk (BD) ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x0B:
                     cout<<"Source Information: Super Audio CD ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x0C:
                     cout<<"Source Information: HD DVD ( "<<SourceINFO<<" )"<<endl;
                     break;
                 case 0x0D:
                     cout<<"Source Information: PMP ( "<<SourceINFO<<" )"<<endl;
                     break;
                 default:
                     cout<<"Source Information: *reserved* ( "<<SourceINFO<<" )"<<endl;
                     break;
                 }
            }
            break;}
        case 0x04:{
            cout<<"InfoFrame Type: Audio InfoFrame"<<endl;
            long IFVersion = HB1;
            long IFLenght = HB2&0x1F;
            if ((IFVersion == 1) && (IFLenght == 10)){
                cout<<"Version: "<<IFVersion<<endl;
                cout<<"Length: "<<IFLenght<<endl;
                 long CT = PB1&0xF0;
                 switch (CT) {
                 case 0x00:{
                     cout<<"CT="<< CT <<" >> Refer to Stream Header"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: PCM ; Audio Stream Standard: IEC 60958-3 [13]"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: AC-3 ; Audio Stream Encoding Standard: ATSC A/58B [12] excluding Annex E ; Audio Stream Transport Standart: IEC 61937-3 [15]"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: MPEG-1 ; Audio Stream Encoding Standard: ISO/IEC 11172-3 [22] Layer 1 or Layer 2 ; Audio Stream Transport Standart: IEC 61937-4 [16]"<<endl;
                     break;}
                 case 0x04:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: MP3 ; Audio Stream Encoding Standard: ISO/IEC 11172-3 [22] Layer 3 ; Audio Stream Transport Standart: IEC 61937-4 [16]"<<endl;
                     break;}
                 case 0x05:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: MPEG2 ; Audio Stream Encoding Standard: ISO/IEC 13818-3 [23] ; Audio Stream Transport Standart: IEC 61937-4 [16]"<<endl;
                     break;}
                 case 0x06:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: AAC LC ; Audio Stream Encoding Standard: ISO/IEC 14496-3 [24] ; Audio Stream Transport Standart: IEC 61937-6 [18]"<<endl;
                     break;}
                 case 0x07:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: DTS; Audio Stream Encoding Standard: ETSI TS 102 114 [37] ; Audio Stream Transport Standart: IEC 61937-5 [17]"<<endl;
                     break;}
                 case 0x08:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: ATRAC ; Audio Stream Encoding Standard: IEC 61909 [14] See also ATRAC [61] ; Audio Stream Transport Standart: IEC 61937-7 [19]"<<endl;
                     break;}
                 case 0x09:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: DSD ; Audio Stream Standard: ISO/IEC 14496-3 [24], subpart 10, See also Super Audio CD [70]"<<endl;
                     break;}
                 case 0x0A:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: E-AC-3 ; Audio Stream Encoding Standard: ATSC A/52B [12] with Annex E ; Audio Stream Transport Standart: IEC 61937-3 [15]"<<endl;
                     break;}
                 case 0x0B:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: DTS-HD ; Audio Stream Encoding Standard: DVD Forum DTS-HD [28] ; Audio Stream Transport Standart: IEC 61937-5 [17]"<<endl;
                     break;}
                 case 0x0C:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: MLP ; Audio Stream Encoding Standard: DVD Forum MLP [27] ; Audio Stream Transport Standart: IEC 61937-9 [21]"<<endl;
                     break;}
                 case 0x0D:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: DST ; Audio Stream Standard:  ISO/IEC 14496-3 [24], subpart 10"<<endl;
                     break;}
                 case 0x0E:{
                     cout<<"CT="<< CT <<" >> Audio Coding Type: WWA Pro ; Audio Stream Encoding Standard: WWA Pro Decoder Specification [30] ; Audio Stream Transport Standart: IEC 61937-8 [20]"<<endl;
                     break;}
                 case 0x0F:{
                     cout<<"CT="<< CT <<" >> Refer to Audio Codding Extension Type (CXT) field in Data Byte 3"<<endl;
                     break;}
                 default:{

                     break;}}
                 long CC = PB1&0x07;
                 switch (CC) {
                 case 0x00:{
                     cout<<"CС="<< CC <<" >> Refer to Stream Header"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"CС="<< CC <<" >> Audio Channel Count: 2 channels"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"CС="<< CC <<" >> Audio Channel Count: 3 channels"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"СС="<< CC <<" >> Audio Channel Count: 4 channels"<<endl;
                     break;}
                 case 0x04:{
                     cout<<"CС="<< CC <<" >> Audio Channel Count: 5 channels"<<endl;
                     break;}
                 case 0x05:{
                     cout<<"CС="<< CC <<" >> Audio Channel Count: 6 channels"<<endl;
                     break;}
                 case 0x06:{
                     cout<<"CС="<< CC <<" >> Audio Channel Count: 7 channels"<<endl;
                     break;}
                 case 0x07:{
                     cout<<"CС="<< CC <<" >> Audio Channel Count: 8 channels"<<endl;
                     break;}
                 default:{
                     break;}}
                 long SF = PB2&0x1C;
                 switch (SF) {
                 case 0x00:{
                     cout<<"SF="<< SF <<" >> Refer to Stream Header"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"SF="<< SF <<" >> Samping Frequency: 32 kHz"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"SF="<< SF <<" >> Samping Frequency: 44.1 kHz (CD) "<<endl;
                     break;}
                 case 0x03:{
                     cout<<"SF="<< SF <<" >> Samping Frequency: 48 kHz "<<endl;
                     break;}
                 case 0x04:{
                     cout<<"SF="<< SF <<" >> Samping Frequency: 88.2 kHz"<<endl;
                     break;}
                 case 0x05:{
                     cout<<"SF="<< SF <<" >> Samping Frequency: 96 kHZ"<<endl;
                     break;}
                 case 0x06:{
                     cout<<"SF="<< SF <<" >> Samping Frequency: 176.4 kHz"<<endl;
                     break;}
                 case 0x07:{
                     cout<<"SF="<< SF <<" >> Samping Frequency: 192 kHz"<<endl;
                     break;}
                 default:{
                     break;}}
                 long SS = PB2&0x03;
                 switch (SS) {
                 case 0x00:{
                     cout<<"SS="<< SS <<" >> Refer to Stream Header"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"SS="<< SS <<" >> Sample Size: 16bit"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"SS="<< SS <<" >> Sample Size: 20bit"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"SS="<< SS <<" >> Sample Size: 24bit"<<endl;
                     break;}
                 default:{
                     break;}}
                 long CXT = PB3&0x1F;
                 switch (CXT) {
                 case 0x00:{
                     cout<<"CXT="<< CXT <<" >> Refer to Stream Header"<<endl;
                     break;}
                 case 0x01:{
                     cout<<"CXT="<< CXT <<"  >> Audio Coding Extension Type: HE-AAC ; Audio Stream Encoding Standard: ISO/IEC 14496-3:2005 [24]; Audio Stream Transport Standart: IEC 61937-6 [18]"<<endl;
                     break;}
                 case 0x02:{
                     cout<<"CXT="<< CXT <<"  >> Audio Coding Extension Type: HE-AAACv2 ; Audio Stream Encoding Standard: ISO/IEC 14496-3:2005/AMD2:2006 [25] ; Audio Stream Transport Standart: IEC 61937-6 [18]"<<endl;
                     break;}
                 case 0x03:{
                     cout<<"CXT="<< CXT <<"  >> Audio Coding Extension Type: AC-3 ; Audio Stream Encoding Standard: ISO/IEC 230003-1:2007 [26]"<<endl;
                     break;}
                 default:{
                     break;}}
                 long CA = PB4&0xFF;
                 switch (CA) {
                 case 0x00:
                     cout<<"top"<<endl;
                     break;
                 default:
                     break;
                 }
                 long DMINH = PB5&0x80;
                 long LSV3 = PB5&0x40;
                 long LSV2 = PB5&0x20;
                 long LSV1 = PB5&0x10;
                 long LSV0 = PB5&0x08;
                 long LFEPBL1 = PB5&0x02;
                 long LFEPBL0 = PB5&0x01;



            }
            break;}
        case 0x05:{
            cout<<"InfoFrame Type: MPEG Source InfoFrame"<<endl;
            break;}
        case 0x06:{
            cout<<"InfoFrame Type: NTSC VBI InfoFrame"<<endl;
            break;}
        default:
            cout<<"invalid"<<endl;
            break;
        }
        long IFVersion = HB1;
        long IFLenght = HB2&0x1F;
        cout<<"InfoFrame_version: "<<IFVersion<<endl;
        cout<<"InfoFrame_length: "<<IFLenght<<endl;
    }
}
