def mochila(objeto, capacidade):
    if objeto == 0:
        if pesos[0] <= capacidade:
            return valores[0]
        else:
            return 0

    nao_colocar = mochila(objeto - 1, capacidade)
    colocar = 0
    if pesos[objeto] <= capacidade:
        colocar = valores[objeto] + mochila(objeto - 1, capacidade - pesos[objeto])
    
    return max(nao_colocar, colocar)


# Tests
valores = [60, 100, 120]
pesos = [10, 20, 30]
capacidade = 30
assert mochila(2, capacidade) == 160

valores = [20, 10, 30, 40, 50]
pesos = [1, 5, 4, 7, 3]
capacidade = 10
assert mochila(4, capacidade) == 100
