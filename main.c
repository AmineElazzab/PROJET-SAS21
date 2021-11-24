#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//   Déclaration global 

int n=3;


// Déclaration de type structe cLt
typedef struct {   // typedef which you can use to give a type a new name
      char CIN[20];
      char Nom[40];
      char Prenom[40];
      float Montant;
}clt ;

//---------compte
clt cpt[60]={{"HH123","azer","def",6000},{"HH456","amine","razi",4000},{"HH789","mehdi","vari",9000}};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Introduire_un_compte_bancaire()
{
    
    int i=n; // n=nomber des comptes deja enregestrer 
        printf("\n\n\t\t\t\t\t /////***** Introduire un compte bancaire *****/////\n\t\t\t\t\t\t-----------------------------------\n");
        printf("**Entrer CIN** :  ");
        scanf("%s", cpt[i].CIN);
        printf("**Entrer Nom**  : ");
        scanf("%s", cpt[i].Nom);
        printf("**Entrer Prenom** : ");
        scanf("%s", cpt[i].Prenom);
        printf("**Entrer Montant** : ");
        scanf("%f",&cpt[i].Montant);
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t ****Operation Reussi****\n");
        n++;
        system("pause");
}
////////////////////////////////////////////////
void Introduire_plusieurs_comptes_bancaires()
{
    int i;
    int n;
     
    printf("\n\n\t\t\t\t /////***** Introduire plusieurs comptes bancaires *****/////\n");
    printf("\n**Entrer le nombre des compte** : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("**Entrer CIN** :  ");
        scanf("%s",cpt[i].CIN);
        printf("**Entrer Nom** : ");
        scanf("%s",cpt[i].Nom);
        printf("**Entrer Prenom** : ");
        scanf("%s", cpt[i].Prenom);
        printf("**Entrer Montant** : ");
        scanf("%f",&cpt[i].Montant);
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t ****Operation Reussi****\n");
        n++;
    }

    system ("pause");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Retrait()  //COMPARESON
{
	    int i, x;
	    char cin[20];
	    float montant;
	    
	    printf("\t\t\t ********** Rerait **********\n");
	    printf("**Entrer CIN** :  ");
        scanf("%s",cin);
        for(i=0;i<n;i++)
        {
        	if(strcmp(cpt[i].CIN,cin)==0)
        	{
        		x=0;
        		break;
			}
			
		}
		if(x==0)
		{
			printf("**Entrer le Montant** : ");
			scanf("%f",&montant);
			cpt[i].Montant-=montant;
			printf("--------------------------------------------------------------------------------------------------------------------\n");
        	printf("\t\t\t\t\t\t ****Operation Reussi****\n");
		}
		else
		printf("**Compte Pas Trouvee** \n");
        system("pause");
}
////////////////////////////////////////////////////
void Depot()

{
	    int i, x;
	    char cin[20];
	    float montant;
	    
	    printf("\t\t\t ********** Depot **********\n");
	    printf("**Entrer CIN** :  ");
        scanf("%s",cin);
        for(i=0;i<n;i++)
        {
        	if(strcmp(cpt[i].CIN,cin)==0)
        	{
        		x=0;
        		break; // pour sorter dans cette boucle
			}
		}
		if(x==0)
		{
			printf("**Entrer le Montant** : ");
			scanf("%f",&montant);
			cpt[i].Montant+=montant;
			printf("--------------------------------------------------------------------------------------------------------------------\n");
        	printf("\t\t\t\t\t\t ****Operation Reussi****\n");
		}
		else
		printf("**Compte Pas Trouvee** \n");
        system("pause");
}

/////////////////////////// DECLARATION DES OPERATIONS ///////////////////////////////////////
void operations()
{
    int choix;
     
    printf("\n\n\t\t\t\t*****////////// Operations //////////*****");
    printf("\n 1* Retrait");
    printf("\n 2* Depot");
    printf("\n **votre choix** : ");
    scanf("%d",&choix);

    switch(choix){

         case 1:{
              Retrait();

          };break;

         case 2:{
               Depot();

          };break;
    }

}
////////////////////////////////////////////////////////// AFFICHAGE /////////////////////////////////////
///// PAR ORDER ASCENDANT//////
void POA()  
{
    int i,j;
    clt tmp;
    
    printf("\n\t\t\t\t ****Affichage par order ascendant**** \n");


    for(i=0;i<n;i++)//boucle pour testi le nombre des comptes
    {
        for(j=i+1;j<n;j++)
        {
            if(cpt[j].Montant<cpt[i].Montant)
            {

                tmp=cpt[i];
                cpt[i]=cpt[j];
                cpt[j]=tmp;  // TRI PAR SELECTION 
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("\t%s \t%s \t%s \t%.2f\n",cpt[i].CIN,cpt[i].Nom,cpt[i].Prenom,cpt[i].Montant);
    }
    system("pause");  //kaytssna ta kandir chi haja
}
///////////////////////////////// Par Ordre Descendant /////////////////////////////////////
void POD()
{
    int i,j;
    clt tmp;
    
    printf("\n \t\t\t\t ****Affichage Par Ordre Descendant****\n ");


    for(i=0;i<n;i++)//boucle pour testi le nombre des comptes
    {
        for(j=i+1;j<n;j++)
        {
            if(cpt[j].Montant>cpt[i].Montant)
            {

                tmp=cpt[i];
                cpt[i]=cpt[j];
                cpt[j]=tmp;  //
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("\t%s \t%s \t%s \t%.2f\n",cpt[i].CIN,cpt[i].Nom,cpt[i].Prenom,cpt[i].Montant);
    }
    system("pause");  
}
///////////////////////Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit//////////////////////////////////////
void POA1()
{
    int i,j;
    float y;
    clt tmp;
    
    printf("\n****Affichage Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)****\n ");
    printf("**Entrer un chiffre** : ");
    scanf("%f",&y);


    for(i=0;i<n;i++)//boucle pour testi le nombre des comptes
    {
        for(j=i+1;j<n;j++)
        {
            if(cpt[j].Montant>cpt[i].Montant)
            {

                tmp=cpt[i];
                cpt[i]=cpt[j];
                cpt[j]=tmp;  //
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(cpt[i].Montant>y)
        printf("\t%s \t%s \t%s \t%.2f\n",cpt[i].CIN,cpt[i].Nom,cpt[i].Prenom,cpt[i].Montant);
    }
    system("pause");  //kaytssna ta kandir chi haja
}
//////////////////Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)////////////////////////////
void POD1()
{
    int i,j;
    float y;
    clt tmp;
    
    printf("\n****Affichage Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)****\n ");
    printf("**Entrer un chiffre** : ");
    scanf("%f",&y);


    for(i=0;i<n;i++)//boucle pour testi le nombre des comptes
    {
        for(j=i+1;j<n;j++)
        {
            if(cpt[j].Montant<cpt[i].Montant)
            {

                tmp=cpt[i];
                cpt[i]=cpt[j];
                cpt[j]=tmp;  //
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(cpt[i].Montant>y)
        printf("\t%s \t%s \t%s \t%.2f\n",cpt[i].CIN,cpt[i].Nom,cpt[i].Prenom,cpt[i].Montant);
    }
    system("pause");  //kaytssna ta kandir chi haja
}
////////////////Recherche par CIN/////////////////////
void Recherche_par_CIN()
{
	 	int i, x;
	 
	    char cin[20];
	    
	    printf("\t\t\t ********** Recherche par CIN **********\n");
	    printf("**Entrer CIN** :  ");
        scanf("%s",cin);
        for(i=0;i<n;i++)
        {
        	if(strcmp(cpt[i].CIN,cin)==0)  //TRI PAR RECHERCHE  EST COMPARESON 
			{
        	
        		x=0;
        		break;
       		}
   		}
        if(x==0)
        	printf("\t%s \t%s \t%s \t%.2f\n",cpt[i].CIN,cpt[i].Nom,cpt[i].Prenom,cpt[i].Montant);
        else
        	printf("CIN  %s n'existe pas \n",cin);
        	system("pause");
}



void Menu_Affichage()
{


    int choix;
     
    printf("\n\n\t\t\t\t*****////////// Affichage //////////*****");
    printf("\n 1* Par Ordre Ascendant");
    printf("\n 2* Par Ordre Descendant");
    printf("\n 3* Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)");
    printf("\n 4* Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)");
    printf("\n 5* Recherche par CIN");
    printf("\n votre choix : ");
    scanf("%d",&choix);

    switch(choix){

        case 1:{
               POA();

          };break;

         case 2:{
               POD();
          };break;

           case 3:{
               POA1();
          };break;

           case 4:{
               POD1();
          };break;

           case 5:{
                 Recherche_par_CIN();
          };break;


}

}


void Fidelisation()
{
	int i,j;
	clt tmp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(cpt[j].Montant>cpt[i].Montant)
			{
				tmp=cpt[i];
				cpt[i]=cpt[j]; //TRI PAR SELECTION 
				cpt[j]=tmp;
			}
		}
		
	}
	for(i=0;i<3;i++)
	{
		cpt[i].Montant+=cpt[i].Montant*0.0013;
	}
			printf("--------------------------------------------------------------------------------------------------------------------\n");
        	printf("\t\t\t\t\t\t ****Operation Reussi****\n");
        	system("pause");
	
}


int main()
{


    int choix;
   do{
    
    printf("\n\n\t\t\t\t////////////////////**Menu Principal**////////////////////\n");
    printf("1* Introduire un compte bancaire \n");
    printf("2* Introduire plusieurs comptes bancaires \n");
    printf("3* Operations \n");
    printf("4* Affichage \n");
    printf("5* Fidelisation \n");
    printf("6* Quitter l-application \n");
    printf("Votre choix : ");
    scanf("%d",&choix );

    switch(choix){

        case 1:{
            Introduire_un_compte_bancaire();

          };break;

         case 2:{
            Introduire_plusieurs_comptes_bancaires();

          };break;

           case 3:{
               operations();

          };break;

           case 4:{
               Menu_Affichage();

          };break;

           case 5:{

				Fidelisation();

          };break;

           case 6:{


          };break;

    }

}while(choix!=6);






    return 0;

}
