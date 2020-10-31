#include <iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include<math.h>
#include<conio.h>
char yaz[]={'Y','A','Z'};
char git[]={'G','Ý','T'};
struct eger{
	char komut[40];
	int numarasi;
	struct eger* next;
    char data[40];
    int adim;
};
struct bul {
	char   degisken[100];
	int    degeri;
	struct bul* next;
};
struct nosu{
    int numarasi;
    int komut;
    struct nosu* next;
    char data[40];
}; 
struct eger* egerse(struct eger* tmp3,int adim) {
	while(tmp3 != NULL) {
        if(adim == tmp3->numarasi) return tmp3;
        else tmp3=tmp3->next;
	}	
	return 0;  		    
}
struct nosu* gitse(struct nosu* tut,int adim) {
	while(tut != NULL) {
        if(adim == tut->numarasi) return tut;
        else tut=tut->next;
	}	
	return 0;  		    
}  // basla ise-->>1 //gir ise-->>2//yaz ise-->>3//islem satiri ise-->>0// 
int sonucagit(int sayi1,int sayi2,int secenek) {
	switch(secenek) {
		case 1: 
		return sayi1*sayi2;
		break;
		case 2: return sayi1/sayi2;
		break;
		case 3: return sayi1=sayi2;
		break;
		case 4:  return sayi1-sayi2;
		break;
		case 5: return sayi1+sayi2;
		break;
		default: return 0;
	}
}
int sayimi(char dizi[],int basamak) {
	int toplam=0,a=basamak,j=0,s=0;
	char sayilar[]={'0','1','2','3','4','5','6','7','8','9'};
	for(int j=0;j<basamak;j++){
		a--;	
     	for(int i=0;i<10;i++) { 
		    if(dizi[j]==sayilar[i]) {
			    toplam+=pow(10,a)*i;
			    s++;
		    } 
     	}
    }
   if(s==basamak) return toplam;
   else return -1;
}
int islemyap(char dizi[],int uzunluk ) {
	for(int i=uzunluk;i>0;i--) {
		if(dizi[i]=='*') return 1;
		else if(dizi[i]=='/') return 2;
		else if(dizi[i]=='=') return 3;
		else if(dizi[i]=='-') return 4;
		else if(dizi[i]=='+') return 5;
	}
    return -1;
}
int islemyap2(char dizi[],int uzunluk ) {
	for(int i=uzunluk;i>0;i--) {
		if(dizi[i]=='*') return i;
	    else if(dizi[i]=='/') return i;
	    else if(dizi[i]=='=') return i;
		else if(dizi[i]=='-') return i;
		else if(dizi[i]=='+') return i;
	}
    return -1;
}
struct bul* arama (struct bul *hjk,char aranan[]){
    while(hjk != NULL)  {
        int a = strcmp( aranan, hjk->degisken);
        if(a==0) return hjk;
        else    hjk=hjk->next;
    }
    return 0;
} 
struct nosu* arama2 (struct nosu *hhh,int aranan){
    while(hhh != NULL)  {
       if(aranan==hhh->numarasi) return hhh;
        hhh=hhh->next;
    }
    return 0;
}
int hicbir(char ad[],struct bul*tmp,struct bul*head,int*degisken_sayisi) {
    int islem2,sayi_1,sayi_2,sayi_3,alt_sinir=0, islem1,sonucumuz=0; 
    if(islemyap2(ad,alt_sinir)!=3) {
        char aranacak[40], aranacak2[40],aranacak3[40],aranacak4[40];
        int ust_sinir=strlen(ad),f=0,k=0,yeni_sinir,g=0;//isaretin yer
        while((islem2!=3 ||islem1!=3) &&ust_sinir>=0 && alt_sinir>=0 ) {
            f++;
            if(f==1) { 
            	if(k==0) ust_sinir-=1;
            	else ust_sinir=ust_sinir-strlen(aranacak)-1;
            	k++;
			    alt_sinir=islemyap2(ad,ust_sinir);
            	islem1=islemyap(ad,ust_sinir);
				for(int s=alt_sinir+1 ; ust_sinir+1>s;s++) {
            		aranacak[g]=ad[s];
            		g++;	 
				}
				aranacak[g] ='\0';
			    if (arama(tmp,aranacak) ==NULL) 	sayi_1=sayimi(aranacak,strlen(aranacak));
				else  sayi_1=arama(tmp,aranacak)->degeri;
			    f++;
			    yeni_sinir=strlen(aranacak);
            }
			if(f==2) {
				ust_sinir=ust_sinir-yeni_sinir-1;
				alt_sinir=islemyap2(ad,ust_sinir);
				islem2=islemyap(ad,ust_sinir);
				g=0;
				for(int s=alt_sinir+1; ust_sinir+1>s;s++) {
            		aranacak2[g]=ad[s];
                    g++;	 
				}
				aranacak2[g] ='\0';
				if(islem1==3 && (strlen(ad)-strlen(aranacak)-strlen(aranacak2))==1) return sayi_1;
				yeni_sinir=strlen(aranacak2);
			    if (arama(tmp,aranacak2) ==NULL) sayi_2=sayimi(aranacak2,yeni_sinir);
				else sayi_2=arama(tmp,aranacak2)->degeri;
			}	
			if((islem1==4 || islem1==5 ) && (islem2==4 || islem2==5 ||islem2==3)) {
				if(islem1==5  && islem2==3) sonucumuz=sonucagit(sayi_1,sayi_2,5);
			    if(islem1==4  && islem2==4) sonucumuz=sonucagit(sayi_1,sayi_2,5)*(-1);
				if(islem1==5  && islem2==5) sonucumuz=sonucagit(sayi_1,sayi_2,5);
				if(islem1==4  && islem2==3) {
				 	if(sayi_1<sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4);
				    if(sayi_1>sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4)*(-1);
					if(sayi_1==sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,6);
				}
			    if((islem1==5 && islem2==4 ) ){
				 	if(sayi_1<sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4);
				    if(sayi_1>sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4)*(-1);
					if(sayi_1==sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,6);
				}
			    if((islem1==4 && islem2==5 ) ){
				    if(sayi_1>sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4);
				 	if(sayi_1<sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4)*(-1);
					if(sayi_1==sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,6);
				}
				sayi_1=sonucumuz;
				f=1;
				islem2=islemyap(ad,ust_sinir);
			    if(islem2==3) {
				    islem1=islemyap(ad,ust_sinir);
				    
				 	if(islem2==3 && islem1==3) return sonucumuz;
			    }
			}
			else if((islem1==1  || islem1==2 )) {
				sonucumuz=sonucagit(sayi_2,sayi_1,islem1);
				sayi_1=sonucumuz;
				if(islem2==3) return sonucumuz;
				islem1=islem2;
				f=1;
			}
			else {
				if((islem1==5 || islem1==4) && (islem2==1 || islem2==2)) {
					ust_sinir=ust_sinir-yeni_sinir-1;
					alt_sinir=islemyap2(ad,ust_sinir);
					g=0;
					for(int s=alt_sinir+1; ust_sinir+1>s;s++) {
            			aranacak3[g]=ad[s];
            			g++;	 
				    }
					aranacak3[g] ='\0';
					yeni_sinir=strlen(aranacak3);
				    if (arama(tmp,aranacak3) ==NULL) sayi_3=sayimi(aranacak3,strlen(aranacak3));
				    else sayi_3=arama(tmp,aranacak3)->degeri;
				    sonucumuz=sonucagit(sayi_2,sayi_3,islem2);
				    sayi_2=sonucumuz;
				    f=2;
				    islem2=islemyap(ad,ust_sinir);
				    
				}
			}		
		}
	}
}
int egerde(struct bul* tmp,struct nosu* tut,char dizi[]){
	char aranacak1[40],aranacak2[40];
	int i,j=0,sy1,sy2,k=0,isaret,isaret2=0;
	for(i=0;i<strlen(dizi);i++) {
		if((dizi[i] != '<') && (dizi[i] != '=') &&(dizi[i] != '>')&& k==0 ) 	aranacak1[i]=dizi[i];
		else{
			if(k==0) isaret=i;
			if(k==0 && (dizi[i+1])=='=')   isaret2=i+1;
			if(k==0 && (dizi[i+1])=='>')    isaret2=i+1;
			if(k==0 && (dizi[i+1])=='<')    isaret2=i+1;
			if(k==0 && isaret2 != 0)  i++;
			k=1;
			aranacak2[j]=dizi[i+1];
			j++;
		}
	}
	if(arama (tmp,aranacak1)==NULL)    sy1=sayimi(aranacak1,strlen(aranacak1));
	else sy1 = arama(tmp,aranacak1)->degeri;
	if(arama (tmp,aranacak2)==NULL)	   sy2=sayimi(aranacak2,strlen(aranacak2));
	else sy2 = arama(tmp,aranacak2)->degeri;
	if(isaret2==0){
		if(dizi[isaret]=='<') {
		    if(sy1<sy2) return 1;
		    else return 0;
	    }
	    if(dizi[isaret]=='>') {
		    if(sy1>sy2) return 1;
		    else return 0;
	    }
   	}
	else {
		if(dizi[isaret]=='<'&& dizi[isaret2]=='=' ) {
		    if(sy1<=sy2) return 1;
		    else return 0;
	    }
        if(dizi[isaret]=='>'&& dizi[isaret2]=='=' ) {
		    if(sy1>=sy2) return 1;
		    else return 0;
	    }
    	if(dizi[isaret]=='='&& dizi[isaret2]=='=' ) {
		    if(sy1==sy2) return 1;
	    	else return 0;
	    }
	}	
}
int hangisi(char dizi[],int uzunluk) {
	if(uzunluk==5) {
	char basla[]={'B','A','S','L','A'};
	for(int i=0;i<5;i++) {
		 if(dizi[i]==basla[i]) {
			    if(i==4) return 6;
		    }
		    else break;
	}
    }
	if(uzunluk==3) {
	
		for(int i=0;i<3;i++) {
		    if(dizi[i]==yaz[i]) {
			    if(i==2) return 1;
		    }
		    else break;
	    }
	char git[]={'G','Ý','T'};
	    for(int i=0;i<3;i++) {
		    if(dizi[i]==git[i]) {
			    if(i==2) return 2;
		    }
		    else break;
	    }
	char gir[]={'G','Ý','R'};
	    for(int i=0;i<3;i++) {
		    if(dizi[i]==gir[i]) {
		        if(i==2) return 3;
		    }
		    else break;
        }
    }
    if(uzunluk==5) {
	char bitir[]={'B','Ý','T','Ý','R'};
	    for(int i=0;i<5;i++) {
		    if(dizi[i]==bitir[i]) {
			    if(i==4) return 5;
		    }
		    else break;
	    }
    }
    if(uzunluk==4) {
	char eger[]={'E','G','E','R'};
	    for(int i=0;i<4;i++) {
		    if(dizi[i]==eger[i]) {
			    if(i==3) return 4;
		    }
		    else break;
        }
    }
    if(uzunluk==4) {
	char yeni[]={'y','e','n','i'};
	    for(int i=0;i<4;i++) {
		    if(dizi[i]==yeni[i]) {
			    if(i==3) return 8;
		    }
		    else break;
        }
    }
    return 0;
}
bool varmi(char dizi[]){
    	int k=0;
    	for(int i=0;i<strlen(dizi); i++) {
    		if((dizi[i]=='[') || (dizi[i]==']')) k++;	
		}
		if(k % 2== 0 && k>0) return true ;
		else return false;
}	
int main(int argc, char** argv) { 	
    char kmt[6]={'h','i','c','b','i','r'};
    char   ad[500];
    struct bul *tmp;//degiskenin baslangýc adresini saklar
    struct nosu *tut;//komut satirlarinin baslangic adresini saklar
    struct eger *tmp3;//egerlerin baslangic adresini saklar
    struct eger *css;
    FILE *okuma=fopen("derleyici.txt","r");
    struct eger *go=(struct eger*)malloc(sizeof(struct eger));
    struct nosu *address=(struct nosu*)malloc(sizeof(struct nosu));
    struct bul *head=(struct bul*)malloc(sizeof(struct bul));//degisken adresleri saklar
    int gercek_sirasayisi=0,degisken_sayisi=0,sonuc,sirasayisi,tr=0,egerde_islem=0;
	while(feof(okuma)==0){		
		int komut=0,adim,m=0,asd=0,dongu=0;
	    fscanf(okuma,"%d %s\n",&sirasayisi,ad);
	    gercek_sirasayisi++;
		if(gercek_sirasayisi!=sirasayisi) {
			printf("\n%d.inci Sira numarasi hatali girilmistir",gercek_sirasayisi);
			return 0;
		}
		if(1==sirasayisi) {
		    address->komut=1;
		    address->numarasi=sirasayisi;
		    if(hangisi(ad,strlen(ad))!=6) return 0;
	    	printf("Program Baslatildi\n");
            tut=address;//komut satirlarinin baslangýç adresini atadik
	        tmp=head;//degiskenlerin baslangic adresini atadik
        }  
	    if(gercek_sirasayisi !=1 ){ 
	     	address->next=(struct nosu*)malloc(sizeof(struct nosu));
	     	address=address->next;
	    }
	   	if(hangisi(ad,strlen(ad))==4) {//egerrrrr
	   	    char ise_mi[40];
	    	address->komut=6;
	    	address->numarasi=sirasayisi;
	    	fscanf(okuma,"%s\n",&ad);
	    	fscanf(okuma,"%s\n",&ise_mi);
	    	strcpy(address->data,ad);
	    	egerde(tmp,tut,ad);
	    	if(egerde(tmp,tut,ad)!=1) m++;
	    		    fscanf(okuma,"%s\n",&ad);
	    		    if(hangisi(ad,strlen(ad))==0) {
	    		    	strcpy(go->data,ad);
	    		    	strcpy(go->komut,kmt);
					}
	    		    if(hangisi(ad,strlen(ad))==1) strcpy(go->komut,yaz);
	    		    if(hangisi(ad,strlen(ad))==2) strcpy(go->komut,git);
	    			go->numarasi=gercek_sirasayisi;
	    			if(egerde_islem==0) 	tmp3=go;
	    			egerde_islem++;
	    	        if(m>0 && hangisi(ad,strlen(ad))==2) dongu=1;
		}   
			if(hangisi(ad,strlen(ad))==0 && (komut==0 || asd==1)&& m==0) {
    		int h,i;
    		char yeni_dizi[40];
	            if(address->komut !=6) address->komut=0;
	    	    if(address->komut !=6) strcpy(address->data,ad);
	            h=hicbir(ad,tmp,head,&degisken_sayisi);
	            for( i=0; i<strlen(ad);i++) {
	            	if(ad[i] !='=') yeni_dizi[i]=ad[i];
	            	else break;
		    	}
		    	yeni_dizi[i]='\0';
			    if(arama(tmp,yeni_dizi) !=0) 	arama(tmp,yeni_dizi)->degeri=h;	
			    else {
			    	head->next=(struct bul*)malloc(sizeof(struct bul));
	                head=head->next;
	                degisken_sayisi++;
	                strcpy(head->degisken,yeni_dizi);
	                head->degeri=h;
		        }
		    }
		if(hangisi(ad,strlen(ad))==8) {
			fscanf(okuma,"%s\n",&ad);
			if(varmi(ad)==1 ) { //matris
		    address->komut=8;
			int j=0,k=0;
	        char matris_adi[40],matris_kapasite[40],str[8],str2[8],matris_kapasite2[40];
	        int kapasite=0,kapasite2=0,s=0,i,l;
	        for( i=0;i<strlen(ad);i++) {
	        	if(ad[i] != '[') {
	            	if(k==0) {
				        matris_adi[j]=ad[i];
		                j++;
		            }
                }
	        	else {
			        k++;
			        if(k==1 && ad[i] == '[') {
		    	        for( l=i+1; l<strlen(ad);l++) {
		    	    	    if(ad[l]== ']') break;
		    	    	    matris_kapasite[s]=ad[l];
		    	    	    s++;
				        }
					    matris_kapasite[s]='\0';
			        	kapasite=sayimi(matris_kapasite,strlen(matris_kapasite));
		        	}
		        	s=0;
		        	if(ad[l+1]=='[') {
		    	        for( l=i+1; l<strlen(ad);l++) {
		    	    	    if(ad[l]== ']') break;
		    	    	    matris_kapasite2[s]=ad[l];
		    	    	    s++;
				        }
					    matris_kapasite2[s]='\0';
			        	kapasite2=sayimi(matris_kapasite2,strlen(matris_kapasite2));
		        	}
		        }
	        }
	        int x=j;
	        if(k==1) {
		        for(int i=0;i<kapasite;i++) {
			        matris_adi[j]='[';
				    sprintf(str,"%d",i);
				    j++;
				    matris_adi[j]=str[0];
				    if(strlen(str)==2) {
					    j++;
					    matris_adi[j]=str[1];
				    }
				    j++;
            	    matris_adi[j]=']';
                    j++;
		            matris_adi[j]='\0';
		        	head->next=(struct bul*)malloc(sizeof(struct bul));
	                head=head->next;
	                degisken_sayisi++;
	                strcpy(head->degisken,matris_adi);
                    j=x;
		        }
	        }
	        if(k==2) {
	        	for(int i=0;i<kapasite;i++) {
	        		for(int b=0;b<kapasite2;b++){
	        		    matris_adi[j]='[';
	        		    sprintf(str,"%d",i);
				        j++;
				        matris_adi[j]=str[0];
				        if(strlen(str)==2) {
					        j++;
					        matris_adi[j]=str[1];
				        }
				        j++;
            	        matris_adi[j]=']';
                        j++;
                        matris_adi[j]='[';
                        sprintf(str2,"%d",b);
				        j++;
				        matris_adi[j]=str2[0];
				        if(strlen(str2)==2) {
					       j++;
					        matris_adi[j]=str2[1];
				        }
				        j++;
            	        matris_adi[j]=']';
                        j++;
                        matris_adi[j]='\0';
                        head->next=(struct bul*)malloc(sizeof(struct bul));
	                    head=head->next;
	                    degisken_sayisi++;
	                    strcpy(head->degisken,matris_adi);
                        j=x;
					}
				}
			}
		}
		}
	   	if(hangisi(ad,strlen(ad))==2 || (address->komut==6 && hangisi(go->komut,strlen(go->komut))==2)) {//git
	   	char yeni_dizi[40];
	        tr=1;
	        fscanf(okuma,"%d\n",&adim);    
        	if(address->komut !=6) address->komut=4;
        	if(address->komut ==6) go->adim=adim;
        	struct nosu* search=gitse(tut,adim);
        	int p=adim,h,i,j=0;
            while((search->numarasi != gercek_sirasayisi+1) && dongu==0){
            	int k=0;
        		switch(search->komut){
                	case 2:
					    if(arama(tmp,search->data) !=0)  scanf("%d",&arama(tmp,search->data)->degeri);	
				        else if(varmi(search->data)==true) {
            	        char a[40];
		                char matris_ad[40],str[8],str2[8],matris_1[40],matris_2[40];
		                char yeni_dizi[40];
		                int i=1,k=0,j=0,s=0,l=0,g=0,c,rt,x=0,pt=0,r;
                        for( i=0;i<strlen(search->data);i++) {
	        	            if(search->data[i] != '[') {
	                        	if(k==0) {
				                    matris_ad[j]=search->data[i];
		                            j++;
		                        }
                            } 
	                	    else {
			                    k++;
			                    if(k==1 && search->data[i] == '[') {
			                    	rt=i;//parantezin açýlma yeri
		    	                    for( l=i+1; l<strlen(search->data);l++) {
		    	    	                if(search->data[l]== ']') break;
		    	    	                matris_1[g]=search->data[l];
		    	    	                g++;
				                    }
				                    matris_1[g]='\0';
				                    pt=l;//köþeli parantezin kapanma yeri
				                    if(arama(tmp,matris_1) !=NULL) c=arama(tmp,matris_1)->degeri;
			        	            sprintf(str,"%d",c);
						            for( r=0;r<strlen(str);r++) matris_ad[rt+1+r]=str[r];
					            	matris_ad[rt+1+r]=']';
						            i=pt+1;
		        	            }
		        	            if(i==strlen(search->data)-1) break;
		        	            if(k==1 && search->data[i]=='[') {
		    	                    for( l=i+1; l<strlen(search->data);l++) {
		    	    	                if(search->data[l]== ']') break;
		    	    	                matris_2[s]=search->data[l];
		    	    	                s++;
				                    }
					                matris_2[s]='\0';
			        	            if(arama(tmp,matris_2) !=NULL) c=arama(tmp,matris_2)->degeri;
			        	            sprintf(str2,"%d",c);
			                    	for(int r=0;r<strlen(str2);r++) matris_ad[l-1]=str2[r];
				                }
		                    }
	                    }
	                    if(arama(tmp,matris_ad) !=NULL) scanf("%d",&arama(tmp,matris_ad)->degeri);
                    }
                    break;
                	case 0:		
					    h=hicbir(search->data,tmp,head,&degisken_sayisi); 
					    for( i=0; i<strlen(search->data);i++) {
	                	    if(search->data[i] !='=') yeni_dizi[i]=search->data[i];
	                	    else break;
			            }
		        	    yeni_dizi[i]='\0';
			            if(arama(tmp,yeni_dizi) !=0) 	arama(tmp,yeni_dizi)->degeri=h;
                        break;
                    case 3: 
                        if(arama(tmp,search->data) !=NULL) printf("%d\n",arama(tmp,search->data)->degeri);
	                    else if(search->data[0]=='"' && search->data[strlen(search->data)-1]=='"'){
		                    for(int i=1;i<strlen(search->data)-1; i++) 	printf("%c",search->data[i]);
		                    printf("\n");
			            }
			            else if(varmi(search->data)==true) { 
            	        char a[40];
            	        int i=1,k=0,j=0,s=0,l=0,g=0,c,rt,x=0,pt=0,r;
		                char matris_addd[40],str3[8],str4[8],matris_3[40],matris_4[40];
		                char yeni_dizi[40];
                        for( i=0;i<strlen(search->data);i++) {
	                	   if(search->data[i] != '[') {
	            	            if(k==0) {
				                    matris_addd[j]=search->data[i];
		                            j++;
		                        }
                            } 
	        	            else {
			                    k++;
			                    if(k==1 && search->data[i] == '[') {
			        	            rt=i;//parantezin açýlma yeri
		    	                    for( l=i+1; l<strlen(search->data);l++) {
		    	    	                if(search->data[l]== ']') break;
		    	    	                matris_3[g]=search->data[l];
		    	    	                g++;
				                    }
				                    matris_3[g]='\0';
				                    pt=l;//köþeli parantezin kapanma yeri
				                    if(arama(tmp,matris_3) !=NULL) c=arama(tmp,matris_3)->degeri;
			        	            sprintf(str3,"%d",c);
						            for( r=0;r<strlen(str3);r++) matris_addd[rt+1+r]=str3[r];
						            matris_addd[rt+1+r]=']';
						            i=pt+1;
		        	            }
		        	            if(i==strlen(search->data)-1) break;
		        	            if(k==1 && search->data[i]=='[') {
		    	                    for( l=i+1; l<strlen(search->data);l++) {
		    	    	                if(search->data[l]== ']') break;
		    	    	                matris_4[s]=search->data[l];
		    	    	                s++;
				                    }
					                matris_4[s]='\0';
			        	            if(arama(tmp,matris_4) !=NULL) c=arama(tmp,matris_4)->degeri;
			        	            sprintf(str4,"%d",c);
			        	            for(int r=0;r<strlen(str4);r++) matris_addd[l-1]=str4[r];
					            }
		                    }
	                    }
	                    if(arama(tmp,matris_addd) !=NULL) printf("%d\n",arama(tmp,matris_addd)->degeri);
                    }
		        	else {
				        int islem_mi;
				        char dizi_yeni[40];
			        	for(i=1;i<6;i++) if( islemyap(search->data,strlen(search->data))==i) islem_mi=1;
	                    if(islem_mi==1) {
	        	            dizi_yeni[0]='h';
	        	            dizi_yeni[1]='=';
	                    	for(i=2;i<strlen(search->data)+2;i++) dizi_yeni[i]=search->data[i-2];
	                    	dizi_yeni[i]='\0';
	                    	h=hicbir(dizi_yeni,tmp,head,&degisken_sayisi);
	                        printf("%d\n",h);
		            	}
			        }
					break;
	                case 6://eger
	                    if(egerde(tmp,tut,search->data)==1) {
	                    	if(hangisi(egerse(tmp3,search->numarasi)->komut,strlen(egerse(tmp3,search->numarasi)->komut))==0) {		
	                        	h=hicbir(egerse(tmp3,search->numarasi)->data,tmp,head,&degisken_sayisi);
	                	        for( i=0; i<strlen(egerse(tmp3,search->numarasi)->data);i++) {
	                            	if(egerse(tmp3,search->numarasi)->data[i] !='=') yeni_dizi[i]=egerse(tmp3,search->numarasi)->data[i];
	                	            else break;
			                    }
		        	            yeni_dizi[i]='\0';
			                    if(arama(tmp,yeni_dizi) !=0) 	arama(tmp,yeni_dizi)->degeri=h;
					        }
	                        if(hangisi(egerse(tmp3,search->numarasi)->komut,strlen(egerse(tmp3,search->numarasi)->komut))==2 )  {
	                            if(gercek_sirasayisi==search->numarasi){
	                                search=gitse(tut,p-1);
	                                adim=p-1;
						        }
	                            else {
	                    	        adim=egerse(tmp3,search->numarasi)->adim-1;
	                    	        search=gitse(tut,adim);
					        	}  
					        }
					      //if(hangisi(egerse(tmp3,search->numarasi)->komut,strlen(egerse(tmp3,search->numarasi)->komut))==1 ) 
					    }
					    else {
						    if(hangisi(egerse(tmp3,search->numarasi)->komut,strlen(egerse(tmp3,search->numarasi)->komut))==2) {
						    }
						    else if(search->numarasi==gercek_sirasayisi) dongu=1;
				    	}
	                break;
	                case 4: 
	                    search=gitse(tut,p-1);
	                    adim=p-1;
	                break;
                    default: return 0;
			        }
			    	adim++;
			    	if(search->numarasi==gercek_sirasayisi) break;
			    	if(j==1) break;
			    	search=search->next;
	        	}   	
        	} 
	        if(hangisi(ad,strlen(ad	))==1)	 {//yaz
	            int islemmi=0,i,h,x=1;
	            char dizi_yeni[40];
	        	if(address->komut!=6) address->komut=3;  
			    address->numarasi=gercek_sirasayisi; 	
	            komut++;
	            fscanf(okuma,"%[^\n]s\n",ad); 
	            if(address->komut==6) {
	            	strcpy(go->data,ad);
				    if(egerde(tmp,tut,address->data)==0)  x=0;
		    	}
	            strcpy(address->data,ad);
	            if(arama(tmp,ad) !=NULL) {
	            	if(x==1) printf("%d\n",arama(tmp,ad)->degeri);
	        	    continue;
			    } 
			    if(x==0) continue;
	            for(i=1;i<6;i++) if( islemyap(ad,strlen(ad))==i) islemmi=1;
	            if(islemmi==1) {
	        	    dizi_yeni[0]='h';
	            	dizi_yeni[1]='=';
	            	for(i=2;i<strlen(ad)+2;i++) dizi_yeni[i]=ad[i-2];
	        	    dizi_yeni[i]='\0';
	            	h=hicbir(dizi_yeni,tmp,head,&degisken_sayisi);
	                printf("%d\n",h);
		    	}
		        else if(ad[0]=='"' && ad[strlen(ad)-1]=='"'){
		            for(int i=1;i<strlen(ad)-1; i++) 	printf("%c",ad[i]);
			    }
			    else if(varmi(ad)==true) { 
            	    char a[40];
            	    int i=1,k=0,j=0,s=0,l=0,g=0,c,rt,x=0,pt=0,r;
		            char matris_add[40],str[8],str2[8],matris_1[40],matris_2[40];
	        	    char yeni_dizi[40];
                    for( i=0;i<strlen(ad);i++) {
	        	       if(ad[i] != '[') {
	            	        if(k==0) {
				                matris_add[j]=ad[i];
		                        j++;
		                    }
                        } 
	            	    else{
			                k++;
			                if(k==1 && ad[i] == '[') {
			            	    rt=i;//parantezin açýlma yeri
		    	                for( l=i+1; l<strlen(ad);l++) {
		    	    	           if(ad[l]== ']') break;
		    	    	           matris_1[g]=ad[l];
		    	    	           g++;
				                }
				                matris_1[g]='\0';
				                pt=l;//köþeli parantezin kapanma yeri
				                if(arama(tmp,matris_1) !=NULL) c=arama(tmp,matris_1)->degeri;
			        	        sprintf(str,"%d",c);
						        for( r=0;r<strlen(str);r++) matris_add[rt+1+r]=str[r];
						        matris_add[rt+1+r]=']';
					    	    i=pt+1;
		            	    }
		        	        if(i==strlen(ad)-1) break;
		        	        if(k==1 && ad[i]=='[') {
		    	                for( l=i+1; l<strlen(ad);l++) {
		    	    	            if(ad[l]== ']') break;
		    	    	            matris_2[s]=ad[l];
		    	    	            s++;
				                }
					            matris_2[s]='\0';
			            	    if(arama(tmp,matris_2) !=NULL) c=arama(tmp,matris_2)->degeri;
			            	    sprintf(str2,"%d",c);
			                	for(int r=0;r<strlen(str2);r++) matris_add[l-1]=str2[r];
					        }
		                }
	                }
	                if(arama(tmp,matris_add) !=NULL) printf("%d\n",arama(tmp,matris_add)->degeri);
                }
	        }
		    if(hangisi(ad,strlen(ad	))==5)	 {//bitti
		        address->komut=5;
		        address->numarasi=gercek_sirasayisi;
                printf("Program Bitirildi");     
                address->next=NULL;	  		    
    	    }
		    if(hangisi(ad,strlen(ad	))==3){//gir
		        char a[40];
		        char matris_ad[40],str[8],str2[8],matris_1[40],matris_2[40];
		        char yeni_dizi[40];
	    	    int i=1,k=0,j=0,s=0,l=0,g=0,c,rt,x=0,pt=0,r;
			    address->komut=2;
	            komut++;
	            fscanf(okuma,"%s\n",ad);
	            strcpy(address->data,ad);
                if(arama(tmp,ad) !=0) 	scanf("%d",&arama(tmp,ad)->degeri);	
                else if(varmi(ad)==true) {
            	    for( i=0;i<strlen(ad);i++) {
	        	        if(ad[i] != '[') {
	                    	if(k==0) {
				                matris_ad[j]=ad[i];
		                        j++;
		                    } 
                        } 
	        	        else{
			                k++;
			                if(k==1 && ad[i] == '[') {
			        	        rt=i;//parantezin açýlma yeri
		    	                for( l=i+1; l<strlen(ad);l++) {
		    	    	           if(ad[l]== ']') break;
		    	    	           matris_1[g]=ad[l];
		    	    	           g++;
				                }
				                matris_1[g]='\0';
				                pt=l;//köþeli parantezin kapanma yeri
				                if(arama(tmp,matris_1) !=NULL) c=arama(tmp,matris_1)->degeri;
			        	        sprintf(str,"%d",c);
						        for( r=0;r<strlen(str);r++) matris_ad[rt+1+r]=str[r];
						        matris_ad[rt+1+r]=']';
						        i=pt+1;
		        	        }
		        	        if(i==strlen(ad)-1) break;
		        	        if(k==1 && ad[i]=='[') {
		    	            for( l=i+1; l<strlen(ad);l++) {
		    	    	        if(ad[l]== ']') break;
		    	    	        matris_2[s]=ad[l];
		    	    	        s++;
				            }
					        matris_2[s]='\0';
			        	    if(arama(tmp,matris_2) !=NULL) c=arama(tmp,matris_2)->degeri;
			        	    sprintf(str2,"%d",c);
			        	    for(int r=0;r<strlen(str2);r++) matris_ad[l-1]=str2[r];
				    	}
		            }
	            }
	            if(arama(tmp,matris_ad) !=NULL) scanf("%d",&arama(tmp,matris_ad)->degeri);
            }
	    	else {	
		    	head->next=(struct bul*)malloc(sizeof(struct bul));
	            head=head->next;
	            degisken_sayisi++;
	            strcpy(head->degisken,ad);
	            scanf("%d",&head->degeri);
            }
		    strcpy(address->data,ad);
	    }  
	    if(degisken_sayisi==1) 			tmp=head;	
	    if(gercek_sirasayisi !=1) address->numarasi=gercek_sirasayisi;
	    if(address->komut==6) {
	        go->next=(struct eger*)malloc(sizeof(struct eger));
	        go=go->next;
	    }
    }
    fclose(okuma);
    while(tmp != NULL) {
        printf("\n%s ******%d \n",tmp->degisken,tmp->degeri);
        tmp=tmp->next;	
	}
	getch();
    return 0;
}
