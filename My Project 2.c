#include<stdio.h>
#include<conio.h>
#include<string.h>
struct table
{
     int group;
     int atom;
     int period;
     char name[30];
     char symbol[22];
     char post[30];
     char com[30]

}t;
void insert()
{
    struct table t;
    FILE*tab;
    int another;
    another ='y';
    while(another == 'y'){

    tab=fopen("file.txt","a");
    printf("\nEnter Atom Name: ");
    scanf("%s",&t.name);
    printf("Enter Symbol: ");
    scanf("%s",&t.symbol);
    printf("Enter Group: ");
    scanf("%d",&t.group);
    printf("Enter Period: ");
    scanf("%d",&t.period);
    printf("Enter Atomic Number: ");
    scanf("%d",&t.atom);
    fwrite(&t, sizeof(t), 1, tab);
    fclose(tab);

    printf("\nEnter another record(y/n)");
    fflush(stdin);
    another = getche();
    }
    admin();

}
void display()
{
    struct table t;
    FILE*tab;
    tab=fopen("file.txt","r");

    while(fread(&t,sizeof(t),1,tab)){


printf("\nAtomic Name:%s \nSymbol: %s\nGroup: %d\nPeriod: %d\nAtom Number: %d\n\n...........\n",t.name,t.symbol,t.group,t.period,t.atom);



    }
    fclose(tab);
    printf("\n1.Back To Admin Mode: \n");
    printf("2.Back To User Mode: \n");
    int z;
    scanf("%d",&z);
    if(z==1){
        admin();
    }
    else if(z==2){
        user();
    }
}
void search()
{
    system("cls");
    struct table t;
    FILE * tab;
    tab = fopen("file.txt","r");
    int another;
    another ='y';
    while(another == 'y'){
    int q;
    printf("Enter the data you want to search by Atomic Number: ");
    scanf("%d",&q);
    while (fread(&t, sizeof(t), 1, tab))
  {

   if (q == t.atom)
   {
    printf("\nAtomic Name:%s \nSymbol: %s\nGroup: %d\nPeriod: %d\nAtom Number: %d\n\n...........\n",t.name,t.symbol,t.group,t.period,t.atom);
   }
  }
  fclose(tab);
  printf("\Want to Search More? (y/n) ");
        fflush(stdin);
        another = getch();
    }
    printf("\n1.Back To Admin Mode: \n");
    printf("2.Back To User Mode: \n");
    int z;
    scanf("%d",&z);
    if(z==1){
        admin();
    }
    else if(z==2){
        user();
    }
}



void delete()
{
    FILE*tab,*tab1;
    struct table t,t1;
    int id,found=0,count=0,another;
    another = 'y';
    while(another == 'y')
    {
    tab=fopen("file.txt","r");
    tab1=fopen("file1.txt","w");
    printf("Enter Atomic Number You want to delete: ");
    scanf("%d",&id);
    while(1)
    {
        fread(&t,sizeof(t),1,tab);

        if(feof(tab))
        {
            break;
        }
        if(t.atom==id){
            found=1;
        }
        else{
            fwrite(&t,sizeof(t),1,tab1);
        }
    }
    fclose(tab);
    fclose(tab1);
    if(found==0){
        printf("Sorry No Record Found\n\n");
    }
    else{
        tab=fopen("file.txt","w");
        tab1=fopen("file1.txt","r");
    }
    while(1)
    {
        fread(&t,sizeof(t),1,tab1);
        if(feof(tab1)){
            break;
        }
        fwrite(&t,sizeof(t),1,tab);

    }
    printf("\nAtomic Number %d Successfully Deleted: \n",id);
    fclose(tab);
    fclose(tab1);

    printf("\nEnter another record(y/n)");
    fflush(stdin);
    another = getche();
    }
    admin();

}


update()

{
    char another;
    struct table t;

    int atn;
    FILE *tab, *tab1;
    tab = fopen("file.txt","r");
    tab1= fopen("tempfile.txt","w");
    another = 'y';
    while(another == 'y'){

        printf("enter the atomic number to modify : ");
        scanf("%d",&atn);

    while(fread(&t,sizeof(t),1,tab))
    {
        if(t.atom==atn)
        {
            printf("Enter New Atomic name,Symbol, Group , Period,Atomic Number  :");
            scanf("%s%s%d%d%d",&t.name,&t.symbol,&t.group,&t.period,&t.atom);
            fwrite(&t,sizeof(t),1,tab1);

        }


    }
    fclose(tab);
    fclose(tab1);
     tab = fopen("file.txt", "w");
     tab1 = fopen("tempfile.txt", "r");
    while (fread(&t, sizeof(t), 1, tab1))
    {
      fwrite(&t, sizeof(t), 1, tab);
    }
  fclose(tab);
  fclose(tab1);
  printf("RECORD UPDATED");
    printf("\nModify another record(y/n)");
    fflush(stdin);
    another = getche();
    }
}



void user_post()
{
    system("cls");
    struct table t;
    FILE*tab;
    int another;
    another ='y';
    while(another == 'y'){

    tab=fopen("file2.txt","a");
    printf("\nWrite down Your Comment: ");
    fflush(stdin);
    gets(t.post);

    fwrite(&t, sizeof(t), 1, tab);
    fclose(tab);

    printf("\nEnter another record(y/n)");
    fflush(stdin);
    another = getche();

    }
    printf("\n1.Back To Admin Mode: \n");
    printf("2.Back To User Mode: \n");
    int z;
    scanf("%d",&z);
    if(z==1){
        admin();
    }
    else if(z==2){
        user();
    }
}
void user_post_display()
{
    system("cls");
    struct table t;
    FILE*tab;
    tab=fopen("file2.txt","r");
    int another;
    another ='y';
    while(another == 'y'){

    while(fread(&t,sizeof(t),1,tab)){

        printf("\n%s",t.post);
}
    fclose(tab);
    printf("\nEnter another record(y/n)");
    fflush(stdin);
    another = getche();
    }
    admin();
}

void admin_comment()
{
    system("cls");
    struct table t;
    FILE*tab;
    int another;
    another ='y';
    while(another == 'y'){

    tab=fopen("file3.txt","a");
    printf("\nWrite down Your Comment: ");
    fflush(stdin);
    gets(t.com);

    fwrite(&t, sizeof(t), 1, tab);
    fclose(tab);

    printf("\nEnter another record(y/n)");
    fflush(stdin);
    another = getche();

    }
    printf("\n1.Back To Admin Mode: \n");
    printf("2.Back To User Mode: \n");
    int z;
    scanf("%d",&z);
    if(z==1){
        admin();
    }
    else if(z==2){
        user();
    }
}

void admin_comment_display()
{
    system("cls");
    struct table t;
    FILE*tab;
    tab=fopen("file3.txt","r");
    int another;
    another ='y';
    while(another == 'y'){

    while(fread(&t,sizeof(t),1,tab)){

        printf("\n%s",t.com);
}
    fclose(tab);
    printf("\nEnter another record(y/n)");
    fflush(stdin);
    another = getche();
    }
    admin();
}




void admin()
{
    system("cls");
    int c;
    printf("\n\t\t\t\t----------------Select your choice---------------\n");
    printf("\n\t\t\t\t1. INSERT Chemical Elements\n\t\t\t\t2. DISPLAY Chemical Elements Information\n\t\t\t\t3. SEARCH Chemical Elements by Atomic Number\n\t\t\t\t4. Delete Chemical Elements");
    printf("\n\t\t\t\t5. Update Chemical Elements \n\t\t\t\t6. User Comment\n\t\t\t\t7. Send Notice to User");
    printf("\n\n\t\t\t\t--------------------------------------------------\n");
    printf("\nEnter your choice:");
    scanf("%d", &c);
    printf("\n");
    if(c==1){
        insert();
    }
    else if(c==2){
        display();
    }
    else if(c==3){
        search();
    }
    else if(c==4){
        delete();
    }
    else if(c==5){
        update();
    }

    else if(c==6){
        user_post_display();
    }
    else if(c==7){
       admin_comment();
    }

}
void user()
{
    int d;
    system("cls");
    printf("\n\t----------------Select your choice---------------\n");
    printf("\n\t1. DISPLAY Chemical Elements Information ");
    printf("\n\t2. SEARCH Chemical Elements by Atomic Number ");
    printf("\n\t3. Post A Comment ");
    printf("\n\t4. See Authority Notice ");


    scanf("%d",&d);
    if(d==1){
        display();
    }
    else if(d==2){
        search();
    }
    else if(d==3){
        user_post();
    }
    else if(d==4){
        admin_comment_display();
    }

}


int main()
{
    int e;
    printf("\n\t\t\t\t---------------Welcome To Periodic Table---------------\n");
    printf("\n\n                  \t   \t\t\tEnter Your Choise\n\n");
    printf("\n");
    printf("                   \t\t\t 1. Admin\n");
    printf("                   \t\t\t 2. User\n");
    scanf("%d",&e);
    if(e==1){
        admin();
    }
    else if(e==2){
        user();
    }
}
