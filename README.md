```markdown
# Maximum Average Pass Ratio - LeetCode 1792

Este repositório contém uma solução em C para o problema **1792. Maximum Average Pass Ratio** do LeetCode. O objetivo é maximizar a média das taxas de aprovação de uma escola, adicionando um número limitado de alunos extras a determinadas turmas.

## Descrição do Problema

Dadas `n` turmas, cada uma com um número de alunos que passaram e o número total de alunos, você pode adicionar `extraStudents` alunos extras a qualquer turma. A taxa de aprovação de uma turma é calculada como `pass / total`. O objetivo é maximizar a média das taxas de aprovação de todas as turmas após a adição dos alunos extras.

### Exemplo

**Entrada:**
```
classes = [[1, 2], [3, 5], [2, 2]], extraStudents = 2
```

**Saída:**
```
0.78333
```

**Explicação:**
- Adicionando um aluno extra à primeira turma: `[2, 3]` → taxa de aprovação = `2/3 ≈ 0.66667`.
- Adicionando outro aluno extra à segunda turma: `[4, 6]` → taxa de aprovação = `4/6 ≈ 0.66667`.
- A terceira turma permanece `[2, 2]` → taxa de aprovação = `2/2 = 1.0`.
- A média das taxas de aprovação é `(0.66667 + 0.66667 + 1.0) / 3 ≈ 0.78333`.

## Solução

A solução utiliza uma **estratégia gulosa** combinada com **ordenação** para maximizar a média das taxas de aprovação. A cada passo, o algoritmo adiciona um aluno extra à turma que proporciona o maior aumento na taxa de aprovação.

### Estrutura do Código

- **Estrutura `Class`:** Representa uma turma com os campos `pass` (alunos que passaram) e `total` (total de alunos).
- **Função `calculaAumento`:** Calcula o aumento na taxa de aprovação ao adicionar um aluno extra.
- **Função `compara`:** Compara duas turmas com base no aumento que um aluno extra proporcionaria.
- **Função `maxAverageRatio`:** Implementa a lógica principal para maximizar a média das taxas de aprovação.
- **Função `main`:** Testa a solução com um exemplo de entrada.

### Complexidade

- **Tempo:** \(O(\text{extraStudents} \times n \log n)\), onde `n` é o número de turmas.
- **Espaço:** \(O(n)\), para armazenar o array de turmas.

## Melhorias Futuras

- Implementar uma **max-heap** para reduzir a complexidade de tempo para \(O(n \log n + \text{extraStudents} \log n)\).
- Adicionar suporte para leitura de entradas dinâmicas (por exemplo, via arquivo ou entrada do usuário).

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests para melhorar o código ou a documentação.

## Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
```