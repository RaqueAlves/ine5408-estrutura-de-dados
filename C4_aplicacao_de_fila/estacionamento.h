// Copyright [2025] <Raquel Alves Pinto>

/*
    *** Importante ***

    O código completo em C3/array_queue.h

*/



void retira_veiculo(structures::ArrayQueue<int> *f, int k) {
    // ... COLOQUE SEU CÓDIGO AQUI ...
    for (int i = 1; i <= k; i++) {
        int val = f->dequeue();
        if (i != k) {
            f->enqueue(val);
        }
    }
}


void mantenha_veiculo(structures::ArrayQueue<int> *f, int k) {
    // ... COLOQUE SEU CÓDIGO AQUI ...
    int n = f->size();
    int escolhido = 0;

    for (int i = 1; i <= n; i++) {
        int val = f->dequeue();
        if (i == k) {
            escolhido = val;
        }
    }

    f->clear();
    f->enqueue(escolhido);
}