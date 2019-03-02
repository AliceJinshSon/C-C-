#include<stdio.h>
#define noVehicles 3
struct Rental{
   int id;
   double tax;
   double baseDay;
   double earnings;
};
double addPostive (double amount, double newAmount){
   if(newAmount>0){
      amount=amount+newAmount;
   }
   else{
      amount=amount;
   }
   return amount;
}
double taxCulc (double price, double rate){
   double tax;
   tax=price*(rate/100);
   return tax;
}

double subtractPositive (double amount, double newAmount){
   if(newAmount>0){
      amount=amount-newAmount;   
      
   }
   else{
      amount=amount;
   }
   return amount;
}

int main(void){
   struct Rental vRent[]={ {123,9.95,0}, {124,19.95,0},{125,29.95,0}};
   int option;
   int i=0;
   int meters=0;
   int tmpID;
   int day;
   int flag;
   double taxes;
   char yesno;
   double totalCost;
   double discountValue=5;
   double taxRate = 14;
   double basePrice;
   double distRate1=0.69;
   double distRate2=0.49;
   double sectionA;
   double sectionB=100;
   double kilometerCost;
   
   printf("***** Rental Vehicle Management App ***** \n");
   do{
      printf("1.) Rental Status \n");
      printf("2.) Apply Charges \n");
      printf("3.) Apply Taxes to All Rentals \n");
      printf("4.) Apply Gift Card \n");
      printf("0.) Log Out");
      printf("\n");
      printf("Please enter an option to continue:");
      scanf("%d",&option);
      printf("\n");
      
      switch(option){
         case 0:
            break;
         case 1:
            printf("-- Rental Vehicle Status -- \n");
            printf("ID#      Earnings \n");
            printf("-------- --------- \n");
            for(i=0; i<3; i++){
               printf("%8d %10.2lf \n", vRent[i].id, vRent[i].earnings);
            }
            printf("\n");
            break;
         case 2:
            flag =-1;
            printf("---Rental Charges--- \n");
            printf("Enter the vehicle ID:");
            scanf("%d",&tmpID);
            int i;
            for(i=0; i<3 && flag==-1; i++){
               if(tmpID==vRent[i].id){
                  flag=i;   
               }   
            }
            if(flag !=-1){
               printf("Enter Rental Period (in Days):");
               scanf("%d",&day);
               basePrice=day*vRent[flag].baseDay;
               printf("Enter kilometers driven :");
               scanf("%d", &meters);
               
               //calculate based on  kilo
               if(meters>100){
                    kilometerCost=(meters-sectionB)*distRate2+sectionB*distRate1;
               }else{
                     kilometerCost=meters*distRate1;
               }
                totalCost=addPostive(basePrice, kilometerCost);
               vRent[flag].earnings = totalCost;
               
               //calculate subtract the discount
                printf("Apply Discount: ");
                scanf("%c", &yesno);
   
               if(yesno=='Y' || yesno =='y'){   
                  totalCost=subtractPositive(totalCost,discountValue);
               }
               else {
                  totalCost= totalCost;
               }
               vRent[flag].earnings = totalCost;   

         
               printf("Base kmCost DiscStatus Total \n");
               printf("==== ====== ========== ===== \n");
               printf("%6.2lf %6.2lf %10c %6.2lf \n",basePrice, kilometerCost, yesno, totalCost);
               
            }
            else {
               printf("Please enter correct Car Id");
            }
            break;
         case 3:
            printf("-- Apply Taxes To all Accounts--");
            printf("ID#      Earnings   Taxes");
            printf("-------- ---------- ------");
               for(i=0; i<noVehicles; i++){
                  vRent[i].tax=taxCulc(vRent[i].earnings, taxRate);
                  vRent[i].earnings=addPostive(vRent[i].earnings, vRent[i].tax);
               printf("%8d %10.2lf %6.2lf\n",vRent[i].id, vRent[i].earnings, vRent[i].tax);
               }
            break;
         
         case 4:
            printf("-- Apply Gift Card --");
            printf("\n");
            printf("Enter the Vehicle ID:");
            int vehicleID;
            int cardAmount;
            scanf("%d",&vehicleID);
               for(i=0; i<vehicleID; i++){
                  if(vehicleID==vRent[i].id){
                     flag=i;
                  }
               }
               if(flag!=-1){
                  printf("Enter Gift Card Amount:");
                  scanf("%lf",&cardAmount);
               vRent[flag].earnings=subtractPositive(vRent[flag].earnings, cardAmount);
               }
               else{
                  printf("ERROR: Vehicle ID does not exist \n");
               }
            break;
         default:
            printf("Error: Please enter a valid option to cotinue \n");
            break;
      }
   }while(option!=0);
   printf("Bye!");
   return 0;
}
