#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>
#include <string.h>

struct Person{
    char firstName[128];
    char lastName[128];
    char nume_judet[3];
};

struct Car{
    char brand[128];
    char licencePlate[9];
    uint16_t yearOfFabrication;
    struct Person* owner;
    uint8_t no_of_owners;
};

struct Person* createPerson() {
    struct Person* persoana = malloc(sizeof(struct Person));
    scanf("%s %s %s",persoana->firstName,persoana->lastName,persoana->nume_judet);
    getchar();
    return persoana;
}

struct Car* createCar() {
    struct Car* masina= malloc(sizeof(struct Car));
    scanf("%s %s %hu",masina->brand,masina->licencePlate,&masina->yearOfFabrication);
    masina->no_of_owners=0;
    return masina;
}

void addCar(struct Car* car, struct Car** cars, uint32_t* no_of_cars) {
    cars = (struct Car**)realloc(cars,(*no_of_cars+1)*sizeof(struct Car));
    cars[*no_of_cars+1]=car;
    (*no_of_cars)++;
    free(cars);
}

struct Car** readData(uint32_t no_of_cars) {
    struct Car** masini=malloc(sizeof(masini)*no_of_cars);
    for(int i=0;i<no_of_cars;i++) {
        masini[i]=malloc(sizeof(struct Car));
    }
    return masini;
}

void sell(struct Car* car, struct Person* new_owner) {
    car->licencePlate[0]=new_owner->nume_judet[0];
    car->licencePlate[1]=new_owner->nume_judet[1];
    for(int i=2;i<strlen(car->licencePlate);i++) {
        car->licencePlate[i]++;
    }
    car->no_of_owners++;
}

void rabla(struct Car* car) {
    car->owner->firstName[0]='\0';
    car->owner->lastName[0]='\0';
    car->no_of_owners=0;
    car->licencePlate[0]='\0';

}
int main() {
    uint32_t NrMasini;
    uint8_t Proprietari;
    scanf("%u",&NrMasini);
    struct Car** AdresaMasini = readData(NrMasini);
    for(int i=0;i<NrMasini;i++) {
        struct Car* Masina=createCar();
        struct Person* persoana=createPerson();
        scanf("%hhu",&Proprietari);
        Masina->owner=persoana;
        Masina->no_of_owners=Proprietari;
        AdresaMasini[i]=Masina;
    }

    char comanda[128],nrinmat[128],nume[128],prenume[128],judet[128];
    getchar();
    while(scanf("%s",comanda)!=EOF) {
        getchar();
        if(strcmp(comanda,"sell")==0) {
            scanf("%s",nrinmat);
            struct Person* PersoanaNoua;
            PersoanaNoua=createPerson();
            for(int i=0;i<NrMasini;i++) {
                if(strcmp(nrinmat,AdresaMasini[i]->licencePlate)==0) {
                    sell(AdresaMasini[i],PersoanaNoua);
                }
            }
        }
        if(strcmp(comanda,"add")==0) {
            struct Car* MasinaNoua;
            MasinaNoua=createCar();
            scanf("%s %s %s",nume,prenume,judet);
            addCar(MasinaNoua,AdresaMasini,&NrMasini);
        }

        if(strcmp(comanda,"rabla")==0) {
            scanf("%s",nrinmat);
            for(int i=0;i<NrMasini;i++) {
                if(strcmp(nrinmat,AdresaMasini[i]->licencePlate)==0) {
                    struct Car* MasinaRabla = AdresaMasini[i];
                    rabla(MasinaRabla);
                }
            }
        }
    }
    for(int i=0;i<NrMasini;i++) {
        if(AdresaMasini[i]->licencePlate[0]!='\0') {
            printf("Masina ");
            printf("%s",AdresaMasini[i]->brand);
            printf(" cu nr. inmatriculare ");
            printf("%s",AdresaMasini[i]->licencePlate);
            printf(" a avut ");
            printf("%hhu",AdresaMasini[i]->no_of_owners);
            printf(" proprietari.\n");
        }
    }
    free(AdresaMasini);

    return 0;
}