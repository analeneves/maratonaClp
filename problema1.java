import java.util.Scanner;
public class vetorExercicio2{
public static void main(final String[] args) {

        final Scanner input = new Scanner(System.in);

        final String[] nome = new String[5];
        final double[] nota = new double[5];
        double soma = 0;
        double media;
        final double maior;

for(int i = 0; i < 5; ++i){
    System.out.println("Digite o nome n"+(i+1)+"º : ");
    nome[i] = input.nextLine();
    System.out.println("Digite a nota do nome n"+(i+1)+"º : ");
    nota[i] = input.nextDouble();
    input.nextLine(); //força a limpeza do buffer...
    soma = soma + nota[i];

    
}
   
  //media = soma/5;
  
  for(int i = 0; i < nota.length; ++i){
    media = soma/nota.length;
    if(nota[i] > media){
     System.out.println("O aluno "+nome[i]+" possui média "+maior+", maior que a média "+media);
  }         
}  
}
}