#include<iostream>
#include<string>
#include<conio.h>
#include<stdio.h>

#define  MAXVERTS 100

using namespace std;

typedef int *pint;

//INICIO CLASES ---------------

class vertice{
	  protected:
	  			string nombre;
	  			int numvert;
	  public:
	  		 vertice(){
			 		   }
			 vertice(string x){
			 		nombre=x;
			 		numvert=-1;			 				
		     }
			 vertice(string x,int n){
			 		nombre=x;
					numvert=n;	
			 }
			 int obtNvert(){
			 	 return numvert;
			 }
		     void ponNvert(int n){
			  	   numvert=n;
		     }
			 string obtNomVert(){
			      return nombre;
			 }	
			 void ponNomVert(string x){
			 	  nombre=x;
		     }
		     bool igual(vertice x){
			 	  return nombre==x.nombre;
		     }
		     bool igual(string x){
			 	  return nombre==x;
		     }
};

class GrafoMatrix{
	  protected:
	  			int maxVerts;
	  			int numVerts;
	  			vertice *verts;
	  			int **matAd;
	  public:
	  		 GrafoMatrix(){
			 	maxVerts=1;
				GrafoMatrix(maxVerts); 		   			
			 }
			 GrafoMatrix(int n){
			 		maxVerts=n;
					verts=new vertice[n];
					matAd=new  pint[n];	
					numVerts=0;
                    //Inicializa la matriz
					for(int i=0;i<n;i++){
							matAd[i]=new int[n];
					}
                    //Se llena de ceros
					for(int i=0;i<n;i++){
						for(int j=0;j<n;j++){
							matAd[i][j]=0;
							}
					}
					
			 }
			 int Onv(){ //Getter de numvert
			 	 return numVerts;
			 }
			 void Pnv(int n){ //Setter de numvert
			 	  	numVerts=n;
			 }
			 int numVertice(string n){
			 	 int i;
			 	 bool encontrado=false;
			 	 for(i=0;(i<numVerts && !encontrado);){
					 encontrado=verts[i].igual(n);
					 if(!encontrado)
					    i++;
			     }
			     if(i<numVerts){
				 		return i;
				 }else{
				 	   return -1;
		         }						 	 
			 }
			 
			 void nuevoVertice(string n){
			 	  bool esta=numVertice(n)>=0;
			 	  if(!esta){
		  			  vertice v=vertice(n,numVerts);
				      verts[numVerts++]=v;		  			  
	  			  }
 	         }
			 void nuevoArco(string a,string b){
			 	  int va=numVertice(a);
			 	  int vb=numVertice(b);
			 	  if(va<0||vb<0)
			 	    cout<<"Vert No existe!";
			 	  else
				      matAd[va][vb]=1;
 	         }
 	         void nuevoArco(int a,int b){
			 	  if((a<0||b<0)&&(a>maxVerts||b>maxVerts))
				  	cout<<"Vert No existe!";
				  else	  								   
					matAd[a][b]=1;
			}		
			bool adyacente(string a,string b){ //Dice si dos nodos son adyacentes
				 int va=numVertice(a);
	 	         int vb=numVertice(b);
	 	          if(va<0||vb<0)
			 	    cout<<"Vert No existe!";
			 	  else
				    return matAd[va][vb]==1;  
	  		}
			bool adyacente(int a,int  b){ //Dice si dos nodos son adyacentes
	 	          if((a<0||b<0)&&(a>maxVerts||b>maxVerts))
			 	    cout<<"Vert No existe!";
			 	  else
				    return matAd[a][b]==1;  
	  		}
	  		int ovalor(string a,string b){ //Devuelve el peso del arco
				int va=numVertice(a);
                int vb=numVertice(b);
                if(va<0||vb<0)
			 	    cout<<"Vert No existe!";
 	            else
				    return matAd[va][vb];
			}		 
		  int ovalor(int a,int b){ //Devuelve el peso del arco
	 	          if((a<0||b<0)&&(a>maxVerts||b>maxVerts))
			 	    cout<<"Vert No existe!";
			 	  else
				    return matAd[a][b];
             }
		 void  pvalor(string a, string b,int n){ //Setea el peso de un arco
		        int va=numVertice(a);
                int vb=numVertice(b);
                if(va<0||vb<0)
			 	    cout<<"Vert No existe!";
			 	else
				     matAd[va][vb]=n;   
			}
		void pvalor(int a,int b,int n){ //Setea el peso de un arco
		       if((a<0||b<0)&&(a>maxVerts||b>maxVerts))
			 	    cout<<"Vert No existe!";
			 	  else
				     matAd[a][b]=n;
			 }
		vertice overtice(int n){
				if(n<0||n>maxVerts)
					cout<<"Vert No existe!";
	 	        else		
	 	            return verts[n];
		}   
		void overtice(vertice v,int n){
				if(n<0||n>maxVerts)
					cout<<"pos invalida!";
	 	        else		
	 	            verts[n]=v;
		}  
		
		void imprimirM(){ //IMprime matriz
			 for(int i=0;i<numVerts;i++){
			 		 for(int j=0;j<numVerts;j++){
					 		 cout<<"["<<matAd[i][j]<<"]";
			         }
					 cout<<endl;
			 }
	    }			 
		void imprimirV(){ //IMprime vertices
			 for(int i=0;i<numVerts;i++){
			 		 cout<<"{"<<verts[i].obtNomVert()<<"}";
			 		 }
	     }		 		 
		void PrintConjunto(){ // Método para imprimir los vértices y arcos en forma de conjunto
			for(int i=0;i<numVerts;i++){
			 	for(int j=0;j<numVerts;j++){
					if(matAd[i][j]!=0)
					  cout<<"{"<<verts[i].obtNomVert()<<", "<<verts[j].obtNomVert()<<", "<<matAd[i][j]<<"}"<<endl;         
			         }
			 }
		}
		void GradoSalida(){ // Método que me permite imprimir el grado de salida de un vértice
			int _Grado=0;
			cout<<"Grados de Salida: "<<endl;
		    for(int i=0;i<numVerts;i++){
			 for(int j=0;j<numVerts;j++){
					if(matAd[i][j]!=0)
					  _Grado+=1;         
			         }
			    cout<<"La ciudad de: "<<verts[i].obtNomVert()<<" tiene un grado de salida: "<<_Grado<<endl;
			    _Grado=0;
			 }
		}
		
		void GradoEntrada(){ //Método que permite ingresar los grados de entrada de un vértice
			int _Grado=0;
			cout<<"\nGrados de Entradas: "<<endl;
		    for(int i=0;i<numVerts;i++){
			 for(int j=0;j<numVerts;j++){
					if(matAd[j][i]!=0)
					  _Grado+=1;         
			         }
			    cout<<"La ciudad de: "<<verts[i].obtNomVert()<<" tiene un grado de entrada: "<<_Grado<<endl;
			    _Grado=0;
			 }
		}
};	
// FIN CLASES ----------

//FUNCIONES AUXILIARES ------------------
int menu (void);
// FIN FUNCIONES AUXIALES ---------------
int main(){
	
	GrafoMatrix ObjGM(10); // Creando Objeto de la clase
  // -------------------------------------------------------------
  string Info;
  string Ciudad_origen;
  string Ciudad_destino;
  int _Distancia;
  
	system("cls");
      int sw=1;
      int opc;
      long opcion;
      do{
         switch(menu()){
           case 1:
           cout<<"ingrese una ciudad: ";
           getline (cin, Info);
           ObjGM.nuevoVertice(Info);
            break;
           case 2:
           	cin.clear();
            cout<<"Ingrese ciudad de Origen: ";
            getline(cin, Ciudad_origen);
            if(Ciudad_origen.compare("")==0) // Presentaba un error al momento de volver a ingresar una distancia
               getline(cin, Ciudad_origen);
            cout<<"Ingrese la ciudad de destino: ";
            getline(cin, Ciudad_destino);
            cout<<"Ingrese la distada representada en Kilometros: ";
            cin>>_Distancia;
            if(cin.fail()){
            	cin.clear();
            	cin.ignore(256, '\n');
            	cout << "Datos erroneos" << endl;
            	system("pause");
            	return;
			}
			if(_Distancia <0 ){
				_Distancia = _Distancia*-1;
			}
            ObjGM.pvalor(Ciudad_origen, Ciudad_destino, _Distancia);
            getch();
            break;
           case 3:
            ObjGM.PrintConjunto();
            getch();
            break; 
           case 4:
             ObjGM.GradoSalida(); //Se implementaro método para imprimir las salidas de un vertice
             ObjGM.GradoEntrada();//Se implementa método para imprimir las entradas de un vértice
             getch();
             break;
           
         }
      }while(sw);  
    
    system("Pause>>NULL");
}

int menu (void){
     int opcion;
     system("CLS");
     system ("color 3A");
       
        printf ("\n\n");
        printf("\t\t\t?????????????????????????????????????????????????\n");
        printf("\t\t\t?      IMPLEMENTACION DE UN GRAFO (CIUDADES)    ?\n");
        printf("\t\t\t?????????????????????????????????????????????????\n");
        printf("\t\t\t?                                               ?\n");
        printf("\t\t\t? 1 -> Crear Ciudad                             ?\n");
        printf("\t\t\t?                                               ?\n");
        printf("\t\t\t? 2 -> Ingrese distancia entre ciudades(KM)     ?\n");
        printf("\t\t\t?                                               ?\n");
        printf("\t\t\t? 3 -> Imprimir en forma de conjunto            ?\n");
        printf("\t\t\t?                                               ?\n");
        printf("\t\t\t? 4 -> Salidas/Entradas de cada ciudad (Grados) ?\n");
        printf("\t\t\t?                                               ?\n");
        printf("\t\t\t?                                               ?\n");
        printf("\t\t\t?                                               ?\n");
        printf("\t\t\t?                                               ?\n");
        printf("\t\t\t?????????????????????????????????????????????????\n");
        printf("\t\t\t?    Elija una opcion...                        ?\n");
        printf("\t\t\t?????????????????????????????????????????????????\n");
 
   int sw=1;
    do {
    opcion=getch();
       if (opcion>='0' && opcion <='4'){
       sw=0;
       }else
        printf("\nSe debe ingresar un entero entre 1 y 9\n");
    
    }while(sw);
    opcion=opcion-'0';
   
   return opcion;
   }
