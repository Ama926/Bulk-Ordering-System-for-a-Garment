#include<iostream.h>
#include<fstream.h>
#include<time.h>
#include<stdlib.h>

const int WP=500,cm=100,pcm=150,tcm=175;         //WP=Work payment, cm=cottonmeter, pcm=polyester cotton meter, tcm=tetran cotton meter
const float vat=0.15;
int Mat,SQ=0,MQ=0,LQ=0,Dsg,allorder=0;
int ordNo;
char response;
//Mat=Material,SQ=Small Quantity,MQ=Medium Quantity,LQ=Large Quantity,Dsg=Design,allorder=Total Order 

class userInput
{
	public:
		void getUserInput()
		{
			ofstream outf("ABOUTORDER.TXT",ios:: app);
			cout<<"Available Materials:\n\t1)Cotten(1m=100/-)\n\t2)Polyester Cotton(1m=150/-)\n\t3)Tetran Cotton(1m=175/-)\n\n"<<endl;
			cout<<"Select a Material : ";
			cin>>Mat;
			outf<<Mat;
		
			if (!(Mat==1 || Mat==2 || Mat==3))
			{
				while(!(Mat==1 || Mat==2 || Mat==3))
				{
					cout<<"Invalid Input. Enter 1,2 or 3\n";
					cout<<"Select a Material : ";
					cin>>Mat;	
					outf<<Mat;
				}
			}	
			cout<<"\n";
			cout<<"Available Designs:\n\t1)Laser(250/-)\n\t2)Sticker(150/-)\n\t3)Sewing(200/-)\n\n"<<endl;
			cout<<"Select a Design: ";
			cin>>Dsg;
			outf<<Dsg;
			
			if (!(Dsg==1 || Dsg==2 || Dsg==3))
			{
				while(!(Dsg==1 || Dsg==2 || Dsg==3))
				{
					cout<<"Invalid Input. Enter 1,2 or 3\n"<<endl;
					cout<<"Select a Design: ";
					cin>>Dsg;					
			    	outf<<Dsg;	
				}		
			}	
			cout<<"\nInput Quantity Of Small T-Shirts	: ";
			cin>>SQ;		
			outf<<SQ;			
			cout<<"Input Quantity Of Medium T-Shirts	: ";
			cin>>MQ;			
			outf<<MQ;			
			cout<<"Input Quantity Of Large T-Shirts	: ";
			cin>>LQ;			
			outf<<LQ;			
			allorder=SQ+MQ+LQ;
			cout<<"Total order is  			: "<<allorder;
			outf<<allorder;
  			outf.close();
		}

};

class SmallTShirt :   public userInput
{
	public:
	int totSmall,sclthcost;
	  SmallTShirt()      //a constructor
	  {
  		totSmall=0;      	//totsmall=Total amount of Small T-Shirts
  		sclthcost=0;        //sclthcost=Cloth Cost			
	  }
   int SmallClothCost()
   {  	    
   		if(Mat==1)
   		{
		   	 sclthcost=cm*2;
   		}        	
   	  else if(Mat==2)
   	  {
  	   	sclthcost=pcm*2;
  	   }             
		else if(Mat==3){
			sclthcost=tcm*2;
		}				
		else
		{
		cout<<"Invalid input\n"<<endl;	
		}
	     return sclthcost;	     
   }
    	int SmallTotal()
   		{
    		if(Dsg==1){
		    	totSmall=(SmallClothCost()+WP+250)*SQ;
		    }	      
 			else if(Dsg==2){
	 			totSmall=(SmallClothCost()+WP+150)*SQ;
			 } 	       
    		else if(Dsg==3){
		    	totSmall=(SmallClothCost()+WP+200)*SQ;
		    }    	   
 			else{
			 cout<<"Invalid input\n"<<endl; 	
			 }	   	  		  
     		return totSmall; 			                       
    		}
};

class mediumTShirt :   public userInput
{
	public:
	int mclthcost,totMedium;
    mediumTShirt()
    {
    	 totMedium=0;
		 mclthcost=0;  	
    }	
   int MediumClothCost()
   {   	    
 	  	if(Mat==1) 
   	  	{
	  	   	mclthcost=cm*3;
		}	 	
        else if(Mat==2)
		{
    	mclthcost=pcm*3;
    	}   	     
	    else if(Mat==3) 
		{
	     mclthcost=tcm*3;	
        }		
	    else
		{
		cout<<"Invalid input\n"<<endl;
	    }
	    return mclthcost;	   	    
  }           
	int MediumTotal()
	{
	   	if(Dsg==1)
	   	{
	   		totMedium=(MediumClothCost()+WP+250)*MQ;
	   	}	      
 	    else if(Dsg==2)
	    {
	 	 totMedium=(MediumClothCost()+WP+150)*MQ;
	    }	      
        else if(Dsg==3)
	    {
    	 totMedium=(MediumClothCost()+WP+200)*MQ;
        }     	  
 	    else
 	    {
	 	cout<<"Invalid input\n"<<endl; 	   
	    }	         	   
        return totMedium;                         	 				
	}
};

class LargeTShirt :   public userInput
{
	public:

	int totLarge;
	float lclthcost;  	
	LargeTShirt()
	{
		totLarge=0;
		lclthcost=0;
	}
      int LargeClothCost()
	  {
  		if(Mat==1)
	  	{
	  	   lclthcost=cm*3.5;
	    }	
   		 else if(Mat==2)
		{
		   lclthcost=pcm*3.5;
        }    	
    	else if(Mat==3)
		{
	    	lclthcost=tcm*3.5;
	    }
    	else
		{
		   cout<<"Invalid input\n"<<endl;
	    }
	    return lclthcost;
	     
	  }
	float LargeTotal()
	{
		if(Dsg==1)
		{
			totLarge=(LargeClothCost()+WP+250)*LQ;	
		}
 		else if(Dsg==2)
	 	{
		 	totLarge=(LargeClothCost()+WP+150)*LQ;
	 	}	       
    	else if(Dsg==3){
	    	totLarge=(LargeClothCost()+WP+200)*LQ;
	    }     	   
 		else
	 	{
		 	cout<<"Invalid input\n"<<endl; 
	 	}	     	       	   
    	 return totLarge; 		 
	}
};
class caltot : public SmallTShirt, public mediumTShirt, public LargeTShirt
{
	protected:
	float Total;	
	public:
	float calTotal()
	{	
		Total=SmallTotal()+ MediumTotal() + LargeTotal();
		return Total;
	}
};
class finaltot : public caltot
{
	protected:
	float VAT,	FinalTotal;
	public:
	finaltot()
	{
		VAT=0;
		FinalTotal=0;
	}
	float calVat()
	{	
	VAT=calTotal()*vat;			//Calculate VAT	
	return VAT;	
	}
	float calFTot()
	{		
	FinalTotal= calTotal()+calVat();	
	return FinalTotal;	
	}
};

class NetAmount: public finaltot
{
	public:
	float Disscount,NetTotal;
	NetAmount()
	{
		Disscount=0;
		NetTotal=0;
	}
	float calDisscount()
	{	
	if(allorder<250)
	{
		Disscount=calFTot()*0;
	}	 
	else if(allorder>=250 && allorder<=500)
	{
		Disscount=calFTot()*0.05;
	}	 
	else if(allorder>500 && allorder<=1000)
	{
		Disscount=calFTot()*0.1;
	}	  
	 else
	 {
 		Disscount=calFTot()*0.2;
 	 }      	   
 	 return Disscount; 			
     }
	float calNettot()
	{
		ofstream calout("NETAMOUNT.txt",ios::app);
		NetTotal=calFTot()-calDisscount();

		calout<<NetTotal<<endl;
		calout.close();
		return NetTotal;
	}	   
};
class displaydata : public NetAmount
{
	public:
	displaydata operator++()
	{
		++ordNo;		
	}
	void disData()
	{
      ifstream inorder("ORDERS.txt",ios::app);
      inorder >>ordNo;

	system("cls");
	cout<<"\n";
	cout<<"\t\t__________Bill of order number "<<ordNo<<"__________";
	cout<<"\n\n";
	cout<<"\n\t\tTotal Cost For All Small T-Shirts  	: Rs."<<SmallTotal()<<endl;
	cout<<"\t\tTotal Cost For All Medium T-Shirts	: Rs."<<MediumTotal()<<endl;
	cout<<"\t\tTotal Cost For All Large T-Shirts	: Rs."<<LargeTotal()<<endl;
	cout<<" \t\t                                         _________";
	cout<<"\n\t\tTotal Cost For All T-Shirts		: Rs."<<calTotal()<<endl;
	cout<<" \t\t                                         _________\n";
	cout<<" \t\t                                         ---------";
	cout<<"\n\t\tTotal Cost of VAT	   		: Rs."<<calVat()<<endl;
	cout<<"\t\tFinal Total is				: Rs."<<calFTot()<<endl;
	cout<<"\t\tDiscount is	      			: Rs."<<calDisscount()<<endl;
	cout<<"\n";
	cout<<"\n\t\tNet total is           		        : Rs."<<calNettot()<<endl;
	cout<<" \t\t                                          _________\n";
	cout<<"  \t\t                                          ---------\n";
	cout<<"\tDo you want another order?(y/n) ";
	cin>>response;

	system("cls");
	}
};
int main()
{
	do
	{
	time_t t;   
    time(&t);
	cout<<"\t\t\t    Needles & Thread Garment\n"<<endl;
	cout<<"\t\t\t********************************\n\n\n"<<endl;
	cout<<"\t   A Program to calculate the Net Amount of a T-Shirt order.\n"<<endl;
	cout<<"\t  `````````````````````````````````````````````````````````\n\n"<<endl;
	cout<<" "<<ctime(&t);
    
     	ofstream outorder("ORDERS.txt",ios::app);
     	cout<<"\nEnter order no: "<<endl; cin>>ordNo;
     	outorder<<ctime(&t);
     	outorder<<ordNo;
     	outorder.close();
     	userInput uI;
     	uI.getUserInput();
     	
     	SmallTShirt sml;
     	sml.SmallClothCost();
     	sml.SmallTotal();
     	
     	mediumTShirt medium;
     	medium.MediumClothCost();
     	medium.MediumTotal();
     	
     	 LargeTShirt large;
     	large.LargeClothCost();
     	large.LargeTotal();
     	
     	caltot tot;
     	tot.calTotal();
     	
     	finaltot ftot;
     	ftot.calVat();
     	ftot.calFTot();
     	
     	NetAmount net;
     	net.calDisscount();
     	
     	displaydata dis;
     	dis.disData();   
		     	
     }while(response!='n');
}
