#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
struct Etudiant
  {
      int NCIN;
      char NOM[20];
      char PRENOM[20];
      int age;
  };
  struct Etudiant Etud;
   struct  BACC
  {   int NCIN;
      float MOYENNE;
      char SERIEBAC[20];
      float NOTEMATH;
      float NOTEPHY;
  };
  struct BACC BAC;
  struct CHOIX
  { int NCIN;
    char CHOIX1[200];
    char CHOIX2[200];
    char CHOIX3[200];
  };
  struct CHOIX CH;

  void CANDIDATURE()//procedure qui fait entrer les etudiants
  {
     struct Etudiant Etud;
     struct BACC BAC;
     struct CHOIX CH;
    FILE *fich ,*fich1,*fich2;
    int rep;
    fich = fopen("etudiants.txt","a");
    fich1 = fopen("bac.txt","a");
    fich2 = fopen("choix.txt","a");
    char CHOIX1[20]="INFORMATIQUE";
    if(fich!=NULL && fich1!=NULL && fich2!=NULL)
    {
    do{
      printf("entrez la NCIN du candidat:\t");
      scanf("%d",&Etud.NCIN);
      printf("entrez le nom du candidat:\t");
      scanf("%s",&Etud.NOM);
      printf("entrez le prenom du candidat:\t");
      scanf("%s",&Etud.PRENOM);
      printf("entrez l'age du candidat:\t");
      scanf("%d",&Etud.age);
      printf("entrez la  moyenne au bacc  du candidat:\t");
      scanf("%f",&BAC.MOYENNE);
      printf("entrez la serie du bac  du candidat:\t");
      scanf("%s",&BAC.SERIEBAC);
      printf("entrez la note de mathematique  du candidat:\t");
      scanf("%f",&BAC.NOTEMATH);
      printf("entrez la note de physique  du candidat:\t");
      scanf("%f",&BAC.NOTEPHY);
      printf("entrez le deuxieme choix  du candidat:\t");
      scanf("%s",&CH.CHOIX2);
      printf("entrez le troisieme choix  du candidat:\t");
      scanf("%s",&CH.CHOIX3);
      fscanf(fich,"%d,%s,%s,%d,%f,%s,%f,%f,%s,%s\n",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&Etud.age);
      fscanf(fich1,"%d,%f,%s,%f,%f\n",&BAC.NCIN,&BAC.MOYENNE,&BAC.SERIEBAC,&BAC.NOTEMATH,&BAC.NOTEPHY);
      fscanf(fich2,"%d,%s,%s,%s\n",&CH.NCIN,&CH.CHOIX1,&CH.CHOIX2,&CH.CHOIX3);
    fclose(fich);
    fclose(fich1);
    fclose(fich2);
      printf("Voulez-vous continuer ?");
      printf("\n1-OUI\n2-NON\n");
      printf("reponse :\t");
      scanf("%d",&rep);
    }while(rep==1);
    }
  }

  int recherche(int Numrech)//fonction qui recherche un etudiant cette fonction permet d'ajouter un etudiant que si son numero n'existe pas;
  { struct Etudiant Etud;
    FILE *fich;
    fich = fopen("etudiants.txt","r");//chemin d'acess qu fichier "etudiants"
    do
    {
       fscanf(fich,"%d;%s;%s;%d\n",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&Etud.age);//permet de lire ligne par lig
       fflush(stdin);//on libere la memoire
       if(Etud.NCIN == Numrech)//on verifie si le numero de l'etudiant est egale au numero recherche
       {
          fclose(fich);
          return 1;//le programme retourne 1 s'il trouve le numero recherche
       }
    }while(!feof(fich));
    fclose(fich);
    return -1;//dans le cas contraire il retourne -1
  }
  /*------------PROCEDURE D'AJOUT------------*/
  void AjouterEtudiant()
  {

    int NCINR;
    int rep;
    FILE *fich;
    fich=fopen("etudiants.txt","a");
    printf("\n Entrer le numero de la NCIN de l'etudiant a ajouter :");
    scanf("%d",&NCINR);
   fflush(stdin);//on libere la memoire
    while(recherche(NCINR)==1)//on verifie si l'etudiant entre existe deja
    {
      printf("\n Cet etudiant existe deja\n");
      printf("\nEntrer le NCIN d'un etudiant qui n'existe pas :");
      scanf("%d",&NCINR);
    }
    struct Etudiant Etud;
    Etud.NCIN=NCINR;
    do{
     printf("\n Entrer le nom :");
    gets(Etud.NOM);
    fflush(stdin);//on libere la memoire
    printf("\n Entrer le prenom :");
    gets(Etud.PRENOM);
    fflush(stdin);//on libere la memoire
    printf("\n Entrer l'age :");
    scanf("%d",&Etud.age);
    fflush(stdin);
    struct CHOIX CH;
    FILE *fich;
    fich = fopen("choix.txt","a");//on ouvre le fichier choix pour ajouter les choix du nouveau candidat
    CH.CHOIX1 [20]= "INFORMATIQUE";
    printf("\n Entrer le CHOIX2 :");
    gets(CH.CHOIX2);
    fflush(stdin);
    printf("\n Entrer le CHOIX3 :");
    gets(CH.CHOIX3);
    fflush(stdin);
    struct BACC BAC;
    //FILE *fich;
    fich = fopen("bacc.txt","a");//on ouvre le fichier bacc pour ajouter les nouveau bacc
    printf("\nEntrer la moyenne obtenue au bac :");
    scanf("%f",&BAC.MOYENNE);
    fflush(stdin);
    printf("\nEntrer la SERIEBACC :");
    gets(BAC.SERIEBAC);//gets:permet d'ecrire les chaines de caractere dans un fichiers
    fflush(stdin);
    printf("\nEntrer la note de mathematique :");
    scanf("%f",&BAC.NOTEMATH);
    //fflush(stdin);
    printf("\nentrer la note en physique :");
    scanf("%f",&BAC.NOTEPHY);
    //fflush(stdin);
    fprintf(fich,"%d;%s;%s;%d\n",Etud.NCIN,Etud.NOM,Etud.PRENOM,Etud.age);
    fprintf(fich,"%s;%s;%s\n",CH.CHOIX1,CH.CHOIX2,CH.CHOIX3);
    fprintf(fich,"%f;%s;%f;%f\n",BAC.MOYENNE,BAC.SERIEBAC,BAC.NOTEMATH,BAC.NOTEPHY);
    fclose(fich);
    printf("Voulez vous continuer ?");
    printf("\n1-oui\n2-non:\t");
    printf("reponse :\t");
    scanf("%d",&rep);
  }while(rep == 1);
}

  void modifier(int NCIN)
{
     int numero,i;
      struct Etudiant Etud;
      struct BACC BAC;
      struct CHOIX CH;
       CH.CHOIX1[20] ="INFORMATIQUE";
     char rep='n';
     printf("entrez le numero de CNI du candidat dont vous voulez modifier le(s) champ(s)\n");
     printf("NCIN :\t");
     scanf("%d",&numero) ;
     if(recherche(numero)==1)//nous verifions si l'etudiant existe
     {
       printf("voulez vous vraiment modifie ? o/n");
       printf("entrer votre reonse :\t");
       scanf("%c",&rep);
      // ffluch(stdin);

       if(rep=='o' || rep=='O')
       {
        FILE *fich;
        FILE *fich2,*fich3,*fich4;
        fich=fopen("etudiants.txt","r");//on ouvre le fichier etudiant pour faire une modification
        fich2=fopen("etudiant2.txt","a");
        fich=fopen("bacc.txt","r");
        fich3=fopen("bacc2.txt","a");
        fich=fopen("choix.txt","r");
        fich4=fopen("choix2.txt","a");

        do{
            fprintf(fich,"%d,%s,%s,%d\n",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&Etud.age);
            fprintf(fich,"%d,%c,%f,%f,%f\n",&BAC.NCIN,&BAC.SERIEBAC,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY);
            fprintf(fich,"%d,%s,%s",&CH.NCIN,&CH.CHOIX2,&CH.CHOIX3);
            if(numero==Etud.NCIN)
            {Etud.NCIN=numero;
            printf("-----------NOUVELLES INFORMATIONS SUR LE CANDIDAT-----------");
            printf("entrez le nouvezau numero de cni du candidat\n");
            scanf("%d",&NCIN);
            printf("entrez le nouveau nom:\n");
            gets(Etud.NOM);
            printf("entrez le nouveau prenom:\n");
            gets(Etud.PRENOM);
            printf("entrez le nouvel age:\n");
            scanf("%d",&Etud.age);
           // fprintf(fich,"%s,%s,%d",Etud.NOM,Etud.PRENOM,ETud.age);
            printf("-----------NOUVELLES INFORMATIONS SUR LE BACC-----------");
            printf("entrer la nouvelle serie :\n");
            gets(BAC.SERIEBAC);
            printf("entrer la nouvelle moyenne :\n");
            scanf("%f",&BAC.MOYENNE);
            printf("entrer la nouvelle note de mathematique :\n");
            scanf("%f",&BAC.NOTEMATH);
            printf("entrer la nouvelle note de physique :\n");
            scanf("%f",&BAC.NOTEPHY);
            printf("-----------NOUVELLES INFORMATIONS SUR LES CHOIX-----------");
            printf("entrer le CHOIX2\n");
            gets(CH.CHOIX2);
            printf("entrer le CHOIX3\n");
            gets(CH.CHOIX3);
            fscanf(fich2,"%d;%s;%s;%d;\n",Etud.NCIN,Etud.NOM,Etud.PRENOM,Etud.age);
            fscanf(fich3,"%s;%f;%f;%f\n",BAC.SERIEBAC,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY);
            fscanf(fich4,"%s;%s;%s\n",CH.CHOIX1,CH.CHOIX2,CH.CHOIX3);
            }
        }while(!feof(fich));
        fclose(fich);
        fclose(fich2);
        fclose(fich3);
        fclose(fich4);
        remove("etudiants.txt");
        rename("etudiant2.txt","etudiants.txt");
        remove("choix.txt");
        rename("choix2.txt","choix.txt");
        remove("bacc.txt");
        rename("bacc2.txt","bacc.txt");
        printf("\n la modification a reussi\n");
      }
      else
      {
          printf("\nla modification a echouee\n");
      }
    }
    else
    {
        printf("\n le numero de l'etudiant n'existe pas\n");
    }
}
void suppession(int NCIN)
{
    int rep;
    int Numsupp;
    struct Etudiant Etud ;
    struct CHOIX CH;
    struct BACC BAC;
    printf("entrer le numero de l'etudiant a supprimer:\n");
    scanf("%d",&Numsupp);
    //fflush(stdin);
    if(recherche(Numsupp)==1)
    {
        printf("\n voulez vous vraiment supprimer :\n");
        printf("1-oui\n2-non\n");
        printf("reponse :\t");
        scanf("%d",&rep);
      //  fflush(stdin);
        if(rep==1)
        {
            FILE *fich,*fich2,*fich3,*fich4,*f,*F;
            fich = fopen("etudiants.txt","r");
            fich2 = fopen("tempetudiants.txt","a");
            f = fopen("choix.txt","r");
            fich3 = fopen("tempchoix.txt","a");
            F = fopen("bacc.txt","r");
            fich4 = fopen("tempbacc.txt","a");
            do{
            fprintf(fich,"%d, %s, %s, %d",Etud.NCIN,Etud.NOM,Etud.NOM,Etud.age);
            fprintf(f,"%s, %s, %s",CH.CHOIX1,CH.CHOIX2,CH.CHOIX3);
            fprintf(F,"%s,%f,%f,%f",BAC.SERIEBAC,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY);
            if(Numsupp!=Etud.NCIN)
            {
                fscanf(fich2,"%d, %s, %s, %d\n",Etud.NCIN,Etud.NOM,Etud.PRENOM,Etud.age);
                fscanf(fich3,"%s, %s, %s\n",CH.CHOIX1,CH.CHOIX2,CH.CHOIX3);
                fscanf(fich4,"%s, %f, %f, %f\n",BAC.SERIEBAC,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY);
            }
        }while(!feof(fich)&&!feof(f)&&!feof(F));
        fclose(fich);
        fclose(fich2);
        remove("etudiants.txt");
        rename("tempetudaints.txt","etudiants.txt");
        fclose(f);
        fclose(fich3);
        remove("choix.txt");
        rename("tempchoix.txt","choix.txt");
        fclose(F);
        fclose(fich4);
        remove("bacc.txt");
        rename("tempbacc.txt","etudiants.txt");
        printf("la suppresion a ete effetue avec succes");
    }
        void resultat()
        { struct Etudiant Etud;
          struct BACC BAC;
          struct CHOIX CH;
          char DECISION[100];
          FILE *F;
          F = fopen("resultat.txt","a");
          float S1 = 12.00,S2 = 10.00,S3 = 09.00;
       do{
          printf("entrer le CNI du candidat :\n");
          scanf("%d",&Etud.NCIN);
           if(recherche(Etud.NCIN)==1)
           {
               if(BAC.MOYENNE >= S1)
               {
                   DECISION[100] = "ADMISENINFO";
                   printf("%s\n",DECISION);
                fscanf(F,"%d, %s, %s ,%f,%f,%f,%s ",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY,&DECISION);
               }
               if(BAC.MOYENNE >= S2 && BAC.MOYENNE<=S1 && BAC.NOTEMATH >S3 && BAC.NOTEPHY >S3)
               {
                   DECISION[100] = "ADMISENINFO";
                   printf("%s\n",DECISION);
                fscanf(F,"%d, %s, %s ,%f,%f,%f,%s ",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY,&DECISION);
               }
               if(BAC.MOYENNE < S1 && BAC.NOTEMATH < S3 || BAC.MOYENNE < S1 && BAC.NOTEPHY < S3)
               {

                   printf("vous est Admis en : %s",CH.CHOIX2);
                   DECISION [100]= "deuxiemechoix";
               fscanf(F,"%d, %s, %s ,%f,%f,%f,%s ",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY,&DECISION);
               }
           }
           else
           {
               printf("ce etudiant ne fait pas partir de la selection \n");
           }
           int rep;
           printf("voulez vous entrer un autre NCIN ?\n 1-OUI\n 2-NON\n");
           printf("reponse :\t");
           scanf("%d",&rep);
        }while(rep==1);
        fclose(F);
    }


}
}
void admis()
{
    struct Etudiant Etud;
    struct BACC BAC;
    char DECISION[200];
    FILE *F;
    F = fopen("resultat.txt","r");
    FILE *F1;
    F1=fopen("admis.txt","a");
    do{
    fprintf(F,"%d, %s, %s ,%f,%f,%f,%s ",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&Etud.age,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY,&DECISION);
    if(DECISION=="ADMISENINFO")
    {
        //fprintf(F,"%d, %s, %s, %s",Etud.NCIN,Etud.NOM,Etud.PRNOM,DECISION);
        fscanf(F1,"%d, %s, %s ,%f,%f,%f ",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&Etud.age,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY);

    }
    }while(!feof(F));
    fclose(F);
    fclose(F1);
}
void selection()
{
  struct Etudiant Etud;
  struct BACC BAC;
  char DECISION[200];
  char CHOIX2;
  FILE *F;
  F=fopen("resultat.txt","r");
  FILE *F5,*F6,*F7,*F8,*F9;
  F5=fopen("MATH.txt","a");
  F6=fopen("PHY.txt","a");
  F7=fopen("CHIMIE.txt","a");
  F8=fopen("BIOS.txt","a");
  F9=fopen("GEOS.txt","a");
  if(F!=NULL && F5!=NULL && F6!=NULL && F7!=NULL && F8!=NULL && F9!=NULL)
  {
      do{
        fprintf(F,"%d,%s,%s,%f,%f,%s",Etud.NCIN,Etud.NOM,Etud.PRENOM,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY);
        if(DECISION!="ADMISENINFO")
            {
                if(CHOIX2=="MATHEMATIQUE")
                   fscanf(F5,"%d,%s,%s,%f,%f,%s",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY);
                 if(CHOIX2=="PHYSIQUE")
                    fscanf(F6,"%d,%s,%s,%f,%f,%s",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY);
                 if(CHOIX2=="CHIMIE")
                    fscanf(F7,"%d,%s,%s,%f,%f,%s",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY);
                 if(CHOIX2=="BIOS")
                    fscanf(F8,"%d,%s,%s,%f,%f,%s",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY);
                 if(CHOIX2=="GIOS")
                    fscanf(F9,"%d,%s,%s,%f,%f,%s",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY);

                 }else{
                 printf("ce candidat est admis en informatique");
                 }
        }while(!feof(F));
  }
  fclose(F);
  fclose(F5);
  fclose(F6);
  fclose(F7);
  fclose(F8);
  fclose(F9);
}
void statiques()
{char DECISION[200];
int totalcandidat=0;
struct Etudiant Etud;
struct BACC BAC;
FILE *F;
F=fopen("resultat.txt","r");
if(F!=NULL)
{
    do{
       fprintf(F,"%d,%s,%s,%f,%f,%s",Etud.NCIN,Etud.NOM,Etud.PRENOM,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY);
       totalcandidat=totalcandidat+1;
    }while(!feof(F));
    printf("le nombre total de candidat en selection est:%d",totalcandidat);
}
int totaladmisinfo=0;
FILE *F1;
F1=fopen("admis.txt","r");
if(F1=NULL)
{ do{
       fprintf(F1,"%d,%s,%s,%f,%f,%s",Etud.NCIN,Etud.NOM,Etud.PRENOM,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY);
       totaladmisinfo=totaladmisinfo+1;
    }while(!feof(F1));
    printf("le nombre total de candidat  selectioner en informatique est:%d",totaladmisinfo);
}
int totaladmismath=0;
FILE *F5;
F5=fopen("MATH.txt","r");
if(F5!=NULL)
{
    do{
       fprintf(F5,"%d,%s,%s,%f,%f,%s",Etud.NCIN,Etud.NOM,Etud.PRENOM,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY);
       totaladmismath =totaladmismath+1;
    }while(!feof(F5));
    printf("le nombre total de candidat envoyer en mathematique est:%d",totaladmismath);
}
int totaladmisphy=0;
FILE *F6;
F6=fopen("phy.txt","r");
if(F6!=NULL)
{ do{
       fprintf(F6,"%d,%s,%s,%f,%f,%s",Etud.NCIN,Etud.NOM,Etud.PRENOM,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY);
       totaladmisphy=totaladmisphy+1;
    }while(!feof(F6));
    printf("le nombre total de candidat  selectioner en physique est:%d",totaladmisphy);
}
int totaladmischimie=0;
FILE *F7;
F7=fopen("chimie.txt","r");
if(F7!=NULL)
{ do{
       fprintf(F7,"%d,%s,%s,%f,%f,%s",Etud.NCIN,Etud.NOM,Etud.PRENOM,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY);
       totaladmischimie=totaladmischimie+1;
    }while(!feof(F7));
    printf("le nombre total de candidat  selectioner en chimie est:%d",totaladmischimie);
}
int totaladmisbios=0;
FILE *F8;
F8=fopen("BIOS.txt","r");
if(F8!=NULL)
{ do{
    fprintf(F8,"%d,%s,%s,%f,%f,%s",Etud.NCIN,Etud.NOM,Etud.PRENOM,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY);
       totaladmisbios=totaladmisbios+1;
    }while(!feof(F8));
    printf("le nombre total de candidat  selectioner en  bios est:%d",totaladmisbios);
}
int totaladmisgios=0;
FILE *F9;
F9=fopen("GIOS.txt","r");
if(F1!=NULL)
{ do{
       fprintf(F9,"%d,%s,%s,%f,%f,%s",Etud.NCIN,Etud.NOM,Etud.PRENOM,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY);
       totaladmisgios=totaladmisgios+1;
    }while(!feof(F9));
    printf("le nombre total de candidat  selectioner en gios est:%d",totaladmisgios);
}
float pourcentageinfo,pourcentagemath,pourcentagephy,pourcentagechimie,pourcentagebios,pourcentagegios;
pourcentageinfo==(totaladmisinfo/totalcandidat)*100;
pourcentagemath==(totaladmismath/totalcandidat)*100;
pourcentagephy==(totaladmisphy/totalcandidat)*100;
pourcentagechimie==(totaladmischimie/totalcandidat)*100;
pourcentagebios==(totaladmisbios/totalcandidat)*100;
pourcentagegios==(totaladmisgios/totalcandidat)*100;
printf("le pourcentage des admis en informatique est:%f",pourcentageinfo);
printf("le pourcentage des admis en mathematique est:%f",pourcentagemath);
printf("le pourcentage des admis en physique  est:%f",pourcentagephy);
printf("le pourcentage des admis en chimie est:%f",pourcentagechimie);
printf("le pourcentage des admis en bios est:%f",pourcentagebios);
printf("le pourcentage des admis en gios est:%f",pourcentagegios);



}
 void suppimer()
 {   struct Etudiant Etud;
     struct BACC BAC;
     char DECISION[200];
     FILE *F1,*F2;
     F1=fopen("admis.txt","r");
     F2=fopen("tempadmis.txt","r");
     if(F1!=NULL && F2!=NULL)
     {
         do{
            fprintf(F1,"%d, %s, %s,%d ,%f,%f,%f,%s ",Etud.NCIN,Etud.NOM,Etud.PRENOM,Etud.age,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY,DECISION);
            if(Etud.age>20)
                {
                fscanf(F2,"%d, %s, %s ,%d,%f,%f,%f,%s ",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&Etud.age,&BAC.MOYENNE,&BAC.NOTEMATH,&BAC.NOTEPHY,&DECISION);
                    }
            }while(!feof(F1));
     }
     remove("admis.txt");
     rename("tempadmis.txt","admis.txt");
     if(!feof(F1))
     {
         fprintf(F1,"%d, %s, %s,%d ,%f,%f,%f,%s ",Etud.NCIN,Etud.NOM,Etud.PRENOM,Etud.age,BAC.MOYENNE,BAC.NOTEMATH,BAC.NOTEPHY,DECISION);
     }
     fclose(F1);
     fclose(F2);
     }


int main()
{
int choix;
int NCIN,rep;
do
{
    system("cls");//permet de vider la console pour pouvoir y reecrire
printf("----------------MENU----------------\n");
printf("faite un choix dans le menu propose :\n");
printf("1-creer une liste de selection d'etudiants en informatique \n");
printf("2-ajouter un etudiant");
printf("3-modifier le(s) champ(s) d'un etudiant\n");
printf("4-supprimer un etudiant\n");
printf("5-afficher la liste des admis en informatique\n");
printf("\nvotre reponse:\t");
scanf("%d",&choix);
switch(choix)
{
case 1:
 CANDIDATURE();
     break;
case 2:
  AjouterEtudiant();
     break;
case 3:
  modifier(NCIN);
     break;
case 4:
   suppession(NCIN);
   break;
case 5:
    admis();
   break;
}
printf("Voulez vous choisir une autre option ?\n");
printf("\n1-OUI\n2-NON\n");
printf("reponse : \t");
scanf("%d",&rep);
}while(rep==1);


return 0;
}
