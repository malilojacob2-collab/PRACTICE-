#include <stdio.h>
#include <string.h>
//shipment data structures
struct Shipment{
int trackingID;
char supplier[50];
char item[50];
float weight;
char mode[10];
char status[20];
float uraFees;
float handlingFees;
float totalCost;
};
struct Shipment s;
FILE*file;
float calculateCost(float weight, float ura, float handling){
float shippingcharge;
float total;
shippingcharge=weight*1500;
total=shippingcharge+ura+handling;
return total;
}

int main(){
    int choice;
    //menu system
    do{
        printf("\nWELCOME TO IMPORT LOGISTICS SYSTEM\n");
        printf("1. Add Shipment Record\n");
        printf("2. Update Shipment Status\n");
        printf("3. Search Shipment\n");
        printf("4. Calculate Shipping Cost\n");
        printf("5. Display all Records\n");
        printf("6. Exit\n");
        printf("Enter Choice:\n");
        scanf("%d", &choice);

        switch(choice){
    case 1:
        file=fopen("shipment_manifest.dat", "ab");
        printf("Enter Tracking ID:\n");
        scanf("%d", &s.trackingID);
        printf("Enter Supplier Name:\n");
        scanf("%s", s.supplier);
        printf("Enter item Name:\n");
        scanf("%s", s.item);
        printf("Enter Weight:\n");
        scanf("%f", &s.weight);
        // for either air or sea
        printf("Enter Shipping Mode(Air/Sea):\n");
        scanf("%s", s.mode);
        //this allows the user to select the status
        printf("Status(a for In-Transit, b for At-customs, c for Arrived):\n");
        scanf("%s", &s.status);
        //this enables a user to carryout calculations
        printf("Enter Handling Fees:\n");
        scanf("%f", &s.uraFees);
        s.totalCost=calculateCost(s.weight,s.uraFees,s.handlingFees);
        fwrite(&s,sizeof(s),1,file);
        fclose(file);
        printf("Shipment Added Sucessfully\n");
        break;
    case 2:
        printf("Shipment Satus Updated Successfully");
        break;
    case 3:
       int id;
       int found=0;
       file=fopen("shipment_manifest.dat", "rb");
       printf("Enter Tracking ID:\n");
       scanf("%d", &id);
       while(fread(&s,sizeof(s),1,file)){
        if(s.trackingID==id){
            found=1;
            printf("Shipment Found\n");
            printf("Supplier:%s\n", s.supplier);
            printf("Status:%s\n", s.status);
            printf("Total Cost:%.2f\n", s.totalCost);
        }

       if(found==0){
        printf("Shipment Not Found!!\n");
       }
       fclose(file);
       }
        break;
    case 4:
        float weight;
        float ura;
        float handling;
        float total;
        printf("Enter weight:\n");
        scanf("%f", &weight);
        printf("Enter URA Fees:\n");
        scanf("%f", &ura);
        printf("Enter Handling Fees:\n");
        scanf("%f", &handling);
        total=weight+ura+handling;
        printf("Total Shipment Cost:%.2f\n", total);
        break;
    case 5:
        file=fopen("shipment_manifest.dat", "rb");
        while(fread(&s,sizeof(s),1,file)){
        printf("\nTracking ID:%d\n", s.trackingID);
        printf("Supplier:%s\n", s.supplier);
        printf("Item:%s\n", s.item);
        printf("Weight:%.2f'tonnes\n",s.weight);
        printf("Mode:%s\n", s.mode);
        printf("Status:%s\n", s.status);
        printf("Total Cost:%.2f\n", s.totalCost);
        }
        fclose(file);

        break;
    case 6:
        printf("Existing program\n");
        printf("\nODONGO JACOB MALILO  2025/DCS/DAY/0135\n");
        break;
    default:
        printf("Invalid Choice\n");

        }
    }
    while(choice!=6);
    return 0;
}
