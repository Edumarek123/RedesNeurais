void RedeNeural::BackPropagation(Matriz entradas){
    //∇Cw_l = a_(l-1) * e_l
    //∇Cb_l = e_l
    for(int i=numero_layers-2;i>=1;i--){
        weights_layers[i]->somar(multiplicar_escalar((multiplicar(*erros[i], transposta(*saidas[i-1]))), LEARNIG_RATE));
        bias_layers[i]->somar(multiplicar_escalar(*erros[i], LEARNIG_RATE));
    }
    weights_layers[0]->somar(multiplicar_escalar((multiplicar(*erros[0], transposta(entradas))), LEARNIG_RATE));
    bias_layers[0]->somar(multiplicar_escalar(*erros[0], LEARNIG_RATE));
}
