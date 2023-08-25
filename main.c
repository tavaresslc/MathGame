#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um número aleatório no intervalo [min, max]
int randomInRange(int min, int max) { return min + rand() % (max - min + 1); }

// Função para apresentar a pergunta e verificar a resposta
int askQuestion(int a, int b, char operator) {
  int userAnswer;
  int correctAnswer;

  // Calcula a resposta correta com base no operador fornecido
  switch (operator) {
  case '+':
    correctAnswer = a + b;
    break;
  case '-':
    correctAnswer = a - b;
    break;
  case '*':
    correctAnswer = a * b;
    break;
  case '/':
    correctAnswer = a / b;
    break;
  }

  // Apresenta a pergunta ao jogador
  printf("Quanto é %d %c %d?\n", a, operator, b);
  scanf("%d", &userAnswer);

  // Verifica se a resposta do jogador está correta
  return userAnswer == correctAnswer;
}

int main() {
  srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
  int level, num1, num2, score = 0;
  do {
    printf("\nBem-vindo ao Jogo de Matemática!\n");
    printf("Escolha o nível de dificuldade:\n");
    printf("1 - Fácil\n");
    printf("2 - Médio\n");
    printf("3 - Difícil\n");
    printf("\nNível: ");
    scanf("%d", &level);

    int numQuestions;
    switch (level) {
    case 1:
      numQuestions = 5;
      break;
    case 2:
      numQuestions = 10;
      break;
    case 3:
      numQuestions = 15;
      break;
    default:
      printf("Nível inválido. Saindo do jogo.\n");
      return 1;
    }

    // Loop para gerar e apresentar perguntas
    for (int i = 0; i < numQuestions; i++) {
      char operators[] = {'+', '-', '*', '/'};
      char operator= operators[randomInRange(0, 3)];

      num1 = randomInRange(1, level * 10);
      num2 = randomInRange(1, level * 10);

      // Verifica se a divisão é inteira para operação de divisão
      if (operator== '/' && num1 % num2 != 0) {
        i--;
        continue;
      }

      printf("\nPergunta %d:\n", i + 1);
      if (askQuestion(num1, num2, operator)) {
        printf("Resposta correta!\n\n");
        score++;
      } else {
        printf("Resposta incorreta.\n\n");
      }
    }

    // Exibe a pontuação final ao final do jogo
    printf("Fim do jogo! Pontuação final: %d/%d\n", score, numQuestions);

    // Pergunta ao jogador se deseja jogar novamente
    char playAgain;
    printf("Deseja jogar novamente? (S/N) ");
    scanf(" %c", &playAgain); // O espaço antes de %c evita o problema do caractere de nova linha

    if (playAgain == 'S' || playAgain == 's') {
      score = 0; // Zera a pontuação para o próximo jogo
    } else {
      printf("\nObrigado por jogar! Até a próxima.\n");
      break;
    }
  } while (1); // Loop infinito até que o jogador decida sair
  return 0;
}