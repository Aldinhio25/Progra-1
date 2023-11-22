#include <stdio.h>
#include <math.h>

/*Calcular hipotenusa, area, perimetro de un t.r*/

void main(){
    float cateto_a, cateto_b, hipotenusa, area, perimetro;
    printf("cateto_a?");
    scanf("%f", &cateto_a);


    printf("cateto_b?");
    scanf("%f", &cateto_b);
    
    hipotenusa = sqrt(cateto_a * cateto_a +  cateto_b * cateto_b);
    area = (cateto_a * cateto_b)/2;
    perimetro = (cateto_a + cateto_b + hipotenusa);

    printf("la hipotenusa es: %f", hipotenusa);
}