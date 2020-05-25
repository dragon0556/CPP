#include <iostream>

using namespace std;

//Data Design Class
class PrintData{

   public:
   void printABC(){
    int i = 0;
    int j = 0;
    int k = 0;
    int l=0;
    
    for( i =0 ; i< 26; i=i+2){
        k=0;
        for( l=0;l<i; l++){
                cout<<setGreen();
            }
        for( j = i; j < 26; j++){
            
            if(j==i){
            printf("%c",(65+j));
            printf("%c",(65+j+1));
            j++;
            }
            cout<<setYellow();
            
            
        }
        for( l=27;l<=52-i-1; l++){
                cout<<setRed();
            }
        for(k=52-i ; k<54 ; k++){
            if( k == 52-i){
               printf("%c",(65+(k-28)));
               printf("%c",(65+(k-28)+1)); 
               k++;
            }
            else{
            cout<<setYellow();
            }
        }
        printf("\n");
    }
    
} 

char setGreen(){
    return ' ';
}

char setRed(){
    return ' ';
}

char setYellow(){
    return ' ';
}
};

//Main Method
int main()
{
    PrintData pd;
    pd.printABC();
    return 0;
}




