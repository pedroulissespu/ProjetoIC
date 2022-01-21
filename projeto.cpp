#include <iostream>
#include <string.h>
#define int long long int
#define endl "\n"
using namespace std;

int op, cont, cap = 1, ind = 0;

struct produto
{
    char nome[100];
    char tipo[50];
    double preco;
    char localdisp[50];
    char identificador[10];
    int quantidadedisp;
};

produto dadoproduto(produto *p);
produto remocao(produto *p);
void listagem(produto *p);
void busca(produto *p);
produto altera(produto *p);
int strcicmp(char const *a, char const *b);
void listagemtipo(produto *p);
void listagempreco(produto *p);
void listagemlocal(produto *p);
void menulista(produto *p);

int32_t main()
{
    produto *p = NULL;

    p = (produto *)malloc(sizeof(produto)*cap);

    cout << "Bem vindo ao programa de Controle de Estoque" << endl
         << endl;

inicio:

    cout << "Digite um numero de 1 ate 7 para as seguintes operacoes : " << endl
         << "1. Adicao de Produto" << endl
         << "2. Remocao de Produto" << endl
         << "3. Busca de Produto" << endl
         << "4. Menu de Tipos de Listagem" << endl
         << "5. Editar/Atualizar Informacoes dos Produtos" << endl
         << "6. Sair do Programa" << endl
         << endl;

    cin >> op;
    cout << endl;

    switch (op)
    {
    case 1:
        system("clear||cls");
    repetecad:
        dadoproduto(p);
        if (ind >= cap)
        {
            cap *= 2;
            p = (produto *)realloc(p, sizeof(produto) * cap);
        }
        cout << "-Deseja adicionar outro produto sim ou nao ? Digite 1 para sim ou 2 para nao : ";
    repetecadfim:
        cin >> op;
        switch (op)
        {
        case 1:
            system("clear||cls");
            goto repetecad;
        case 2:
            cout << "Produto(s) Adicionado com Sucesso ! " << endl
                 << endl;
            system("clear||cls");
            break;
        default:
            cout << "Opcao invalida , tente novamente :";
            goto repetecadfim;
        }
        goto inicio;
    case 2:
        system("clear||cls");
        remocao(p);
        getchar();
        system("clear||cls");
        goto inicio;
    case 3:
        system("clear||cls");
        busca(p);
        getchar();
        system("clear||cls");
        goto inicio;
    case 4:
        system("clear||cls");
        menulista(p);
        getchar();
        system("clear||cls");
        goto inicio;
    case 5:
        system("clear||cls");
        altera(p);
        goto inicio;
    case 6:
        cout << "-Saindo do Programa !-" << endl;
        break;
    default:
        cout << "!Opcao invalida , tente novamente selecionando uma opcao valida!" << endl
             << endl;
        goto inicio;
    }
    free(p);
    return 0;
}

void listagem(produto *p)
{
    int k, l;
    produto aux;

    cout << "-A seguir , a listagem de todos os produtos cadastrado ate o momento-" << endl
         << endl;

    if (ind == 0)
    {
        cout << "Ainda nao existe produto(s) salvo no sistema , adicione algum produto e tente novamente" << endl;
    }
    
    else
    {
        for (k = 0; k < ind; k++)
        {
            aux = p[k];
            for (l = k; (l > 0) && (strcicmp(aux.nome, p[l - 1].nome) < 0); l--)
                p[l] = p[l - 1];
            p[l] = aux;
        }

        for (int i = 0; i < ind; i++)
        {
            cout << "-------PRODUTO " << i + 1 << "--------" << endl;
            cout << "Nome do Produto : " << p[i].nome << endl;
            cout << "Tipo do Produto : " << p[i].tipo << endl;
            cout << "Preco do Produto : R$ " << p[i].preco << endl;
            cout << "Local com Disponibilidade : " << p[i].localdisp << endl;
            cout << "Identificador : " << p[i].identificador << endl;
            cout << "Quantidade Disponivel : " << p[i].quantidadedisp << endl;
            cout << "-----------------------" << endl;
        }
    }
}

void busca(produto *p)
{
    bool vef;
    cout << "-Opcao : Busca de Produto, Selecionada com Sucesso-" << endl
         << endl;
buscaagain:
    getchar();

    char busca[100];

    if (ind == 0)
    {
        cout << "Ainda nao existe produto(s) salvo no sistema , adicione algum produto e tente novamente" << endl;
    }
    else
    {
        cout << "-Por favor , digite o nome do produto ou o identificador que deseja buscar : ";
        fgets(busca, 102, stdin);

        for (int i = 0; i < ind; i++)
        {
            if ((strcicmp(busca, p[i].nome) == 0) || (strcmp(busca, p[i].identificador) == 0))
            {
                cout << "-Produto encontrado com sucesso !-" << endl
                     << endl;

                cout << "----------PRODUTO----------" << endl;
                cout << "Nome do Produto : " << p[i].nome << endl;
                cout << "Tipo do Produto : " << p[i].tipo << endl;
                cout << "Preco do Produto : R$ " << p[i].preco << endl;
                cout << "Local com Disponibilidade : " << p[i].localdisp << endl;
                cout << "Identificador : " << p[i].identificador << endl;
                cout << "Quantidade Disponivel : " << p[i].quantidadedisp << endl;
                cout << "---------------------------" << endl
                     << endl;
                vef = true;
                break;
            }
            vef = false;
        }

        if (!vef)
        {
            cout << "-Nao foi possivel encontrar o produto-" << endl
                 << endl;
        }
    buscaopagain:
        cout << "-Deseja realizar outra busca ? Digite 1 para sim ou 2 para nao-" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            system("clear||cls");
            goto buscaagain;
        case 2:
            break;
        default:
            cout << "!Opcao invalida , tente novamente selecionando uma opcao valida!" << endl;
            goto buscaopagain;
        }
    }
    cout << "-Aperte a tecla ENTER para continuar-" << endl;
}

produto remocao(produto *p)
{
    cout << "-Opcao : Remocao de Produto, Selecionada com Sucesso-" << endl;

    cont = 0;

    char codiden[100];

    if (ind == 0)
    {
        cout << "Ainda nao existe produto(s) salvo no sistema , adicione algum produto e tente novamente" << endl;
        cout << "Aperte a tecla ENTER para continuar" << endl;
        getchar();
        return *p;
    }

    cout << "Por favor , verifique qual produto voce deseja realmente remover de acordo" << endl
         << "o identificador com a listagem a seguir : " << endl
         << endl;

    listagem(p);

    getchar();

    cout << "Digite o identificador do produto ou nome que deseja remover : ";
    fgets(codiden, 102, stdin);

    for (int i = 0; i < ind; i++)
    {
        if ((strcmp(codiden, p[i].identificador) == 0) || strcicmp(codiden, p[i].nome) == 0)
        {
            for (int j = i; j < ind; j++)
            {
                p[j] = p[j + 1];
            }
            ind--;
            cont++;
            break;
        }
    }

    if (cont > 0)
    {
        cout << "Produto excluido com sucesso" << endl;
        cout << "Pressione a tecla ENTER para continuar" << endl;
    }
    else
    {
        cout << "Identificador ou nome Invalido !" << endl;
        cout << "Pressione a tecla ENTER para continuar" << endl;
    }

    return *p;
}

produto dadoproduto(produto *p)
{

    char quantidade[19], precoprod[10], identifica[10], nome[100], ncopy[100], ncopy2[100];

    cout << "-Opcao : Adicao de Produto, Selecionada com Sucesso-" << endl
         << endl;
    produto a;
repeteprocesso:
repetecad:
    getchar();
    cout << "-Digite o nome do produto ate 100 caracteres: ";
    fgets(nome, 102, stdin);

    strcpy(ncopy, nome);

    for (int i = 0; i < strlen(nome) - 1; i++)
        ncopy[i] = tolower(ncopy[i]);

    for (int i = 0; i < ind; i++)
    {
        strcpy(ncopy2, p[i].nome);

        for (int j = 0; j < strlen(p[i].nome) - 1; j++)
            ncopy2[j] = tolower(ncopy2[j]);

        if (strcmp(ncopy, ncopy2) == 0)
        {
            cout << "-Produto ja existe-" << endl;
            return *p;
        }
    }

    strcpy(a.nome, nome);

    cout << endl;

    cout << "-Digite qual vai ser o tipo do produto : ";
    fgets(a.tipo, 52, stdin);

    cout << endl;

repetepreco:
    cout << "-Digite o preco do produto(Preco maximo ate 10 digitos contando com o ponto) : ";
    fgets(precoprod, 12, stdin);

    bool vefpreco = true;

    for (int i = 0; i < strlen(precoprod) - 1; i++)
        if (!isdigit(precoprod[i]) && precoprod[i] != '.')
        {
            vefpreco = false;
            break;
        }

    if (vefpreco)
        a.preco = atof(precoprod);
    else
    {
        cout << "-Digite um preco valido-" << endl
             << endl;
        goto repetepreco;
    }

    cout << endl;

    cout << "-Digite o local onde o produto se encontra disponivel : ";
    fgets(a.localdisp, 52, stdin);

    cout << endl;

repeteidentifica:
    cout << "-Digite o identificador do produto , pode ser composto por letras e numeros ate 10 digitos : ";
    fgets(identifica, 12, stdin);

    for (int i = 0; i < ind; i++)
    {
        if (strcmp(identifica, p[i].identificador) == 0)
        {
            cout << "-Identificador ja existe em outro produto-" << endl;
            cout << "-Tente novamente digitando outro identificador valido-" << endl;
            goto repeteidentifica;
        }
    }

    strcpy(a.identificador, identifica);

    cout << endl;

repetequant:
    cout << "-Digite a quantidade disponivel do produto no estoque : ";
    fgets(quantidade, 21, stdin);

    bool vefquant = true;

    for (int i = 0; i < strlen(quantidade) - 1; i++)
        if (!isdigit(quantidade[i]))
        {
            vefquant = false;
            break;
        }

    if (vefquant)
        a.quantidadedisp = atoll(quantidade);
    else
    {
        cout << "-Digite uma quantidade disponível no estoque valida-" << endl
             << endl;
        goto repetequant;
    }

    cout << endl;

    p[ind] = a;
    ind++;
    return *p;
}

produto altera(produto *p)
{
    cout << "-Opcao : Editar/Atualizar Informacoes dos Produtos, Selecionada com Sucesso-" << endl
         << endl;

    getchar();

    char nome[100], ncopy[100], ncopy2[100], busca[100], precoprod[10], identifica[10], quantidade[19];
    bool vefpreco, vefquant;

    if (ind == 0)
    {
        cout << "Ainda nao existe produto(s) salvo no sistema , adicione algum produto e tente novamente" << endl;
        cout << "Aperte a tecla ENTER para continuar" << endl;
        getchar();
        system("clear||cls");
        return *p;
    }

    cout << "Por favor , verifique qual produto voce deseja realmente editar/atualizar de acordo" << endl
         << "com o identificador ou nome com a listagem a seguir : " << endl
         << endl;

    listagem(p);

    cout << "Digite o identificador ou nome do produto que deseja editar/alterar : ";
    fgets(busca, 102, stdin);

    for (int i = 0; i < ind; i++)
    {
        if ((strcicmp(busca, p[i].nome) == 0) || (strcmp(busca, p[i].identificador) == 0))
        {
            system("clear||cls");
            cout << "Produto encontrado com sucesso !" << endl
                 << endl;
        menuselec:
            cout << "Selecione das seguintes opcoes , o que deseja editar : " << endl;
            cout << endl;
            cout << "1. Nome do Produto" << endl
                 << "2. Tipo do Produto" << endl
                 << "3. Preco do Produto" << endl
                 << "4. Local Disponivel" << endl
                 << "5. Identificador do Produto" << endl
                 << "6. Quantidade Disponivel no Estoque" << endl
                 << "7. Voltar para o menu principal" << endl;
            cin >> op;
            switch (op)
            {
            case 1:
                cout << "Alteracao de nome escolhido com sucesso" << endl
                     << endl;
            continuaop1:
                cout << "O novo nome do produto nao pode ser igual ao anterior ou com algum" << endl;
                cout << "Algum produto que ja existe na lista" << endl;
                getchar();

                cout << "Digite o novo nome do produto : ";
                fgets(nome, 102, stdin);

                strcpy(ncopy, nome);

                for (int j = 0; j < strlen(nome) - 1; j++)
                    ncopy[j] = tolower(ncopy[j]);

                for (int j = 0; j < ind; j++)
                {
                    strcpy(ncopy2, p[j].nome);

                    for (int k = 0; k < strlen(p[j].nome) - 1; k++)
                        ncopy2[k] = tolower(ncopy2[k]);

                    if (strcmp(ncopy, ncopy2) == 0)
                    {
                        cout << "-Nome ja esta sendo utilizado-" << endl;
                        cout << "-Caso queira selecionar outra opcao de edicao digite 1 , caso o contrario , digite 2 para continuar" << endl;
                    selecaoop:
                        cin >> op;
                        switch (op)
                        {
                        case 1:
                            system("clear||cls");
                            goto menuselec;
                        case 2:
                            system("clear||cls");
                            goto continuaop1;
                        default:
                            cout << "!Opcao invalida!" << endl;
                            cout << "Por favor , selecione uma opcao valida" << endl;
                            goto selecaoop;
                        }
                    }
                }

                strcpy(p[i].nome, nome);
                cout << "Alteracao de nome realizada com sucesso !" << endl;
                cout << "Aperte a tecla ENTER para voltar para o menu de selecao de alteracao" << endl;
                getchar();
                system("clear||cls");
                goto menuselec;
            case 2:
                cout << "Alteracao do tipo do produto escolhido com sucesso" << endl;
                cout << "Digite a seguir qual vai ser o novo tipo do produto : ";
                getchar();
                fgets(p[i].tipo, 52, stdin);
                cout << "Alteracao do tipo do produto realizada com sucesso !" << endl;
                cout << "Aperte a tecla ENTER para voltar para o menu de selecao de alterecao" << endl;
                getchar();
                system("clear||cls");
                goto menuselec;
            case 3:
                cout << "Alteracao do preco do produto escolhio com sucesso" << endl;
            continuaop3:
                cout << "A seguir digite o preco do produto com maximo ate 10 caracteres contando com o ponto : ";
                getchar();

                fgets(precoprod, 12, stdin);

                vefpreco = true;

                for (int j = 0; j < strlen(precoprod) - 1; j++)
                    if (!isdigit(precoprod[j]) && precoprod[j] != '.')
                    {
                        vefpreco = false;
                        break;
                    }

                if (vefpreco)
                {
                    p[i].preco = atof(precoprod);
                    cout << "Alteracao do preco realizado com sucesso!" << endl;
                    cout << "Aperte a tecla ENTER para voltar ao menu de selecao de alteracao" << endl;
                    getchar();
                    system("clear||cls");
                    goto menuselec;
                }
                else
                {
                    cout << "-O preco digitado eh invalido-" << endl;
                selecaoop3:
                    cout << "Caso queira selecionar outra opcao digite 1, caso o contrario, digite 2 para tentar novamente : ";
                    cin >> op;
                    switch (op)
                    {
                    case 1:
                        system("clear||cls");
                        goto menuselec;
                    case 2:
                        system("cls||clear");
                        goto continuaop3;
                    default:
                        cout << "!Opcao invalida!" << endl;
                        cout << "Por favor , selecione uma opcao valida" << endl;
                        goto selecaoop3;
                    }
                }
            case 4:
                cout << "Alteracao do local com a disponibilidade do produto selecionado com sucesso" << endl;
                cout << "Digite qual vai ser o novo local que vai ter o produto disponivel : ";
                getchar();
                fgets(p[i].localdisp, 52, stdin);
                cout << "Alteracao do local com a disponibilidade realizada com sucesso !" << endl;
                cout << "Aperte a tecla ENTER para voltar para o menu de selecao de alterecao" << endl;
                getchar();
                system("clear||cls");
                goto menuselec;
            case 5:
                cout << "Alteracao do identificador do produto selecionado com sucesso" << endl;
                cout << "O novo identificador nao pode ser o anterior ou já existente" << endl;
            continuaop5:
                getchar();
                cout << "Digite o novo identificador do produto : ";
                fgets(identifica, 12, stdin);

                for (int j = 0; j < ind; j++)
                {
                    if (strcmp(identifica, p[j].identificador) == 0)
                    {
                        cout << "-Identificador ja existe-" << endl;
                        cout << "-Tente novamente digitando outro identificador valido-" << endl;

                    selecaoop5:

                        cout << "Caso queira selecionar outra opcao digite 1, caso o contrario, digite 2 para tentar novamente : ";
                        cin >> op;
                        switch (op)
                        {
                        case 1:
                            system("clear||cls");
                            goto menuselec;
                        case 2:
                            system("cls||clear");
                            goto continuaop5;
                        default:
                            cout << "!Opcao invalida!" << endl;
                            cout << "Por favor , selecione uma opcao valida" << endl;
                            goto selecaoop5;
                        }
                    }
                }
                strcpy(p[i].identificador, identifica);
                cout << "Alteracao do identificador realizado com sucesso !" << endl;
                cout << "Aperte a tecla ENTER para voltar para o menu de selecao de alterecao" << endl;
                getchar();
                system("clear||cls");
                goto menuselec;
            case 6:
                cout << "Alteracao na quantidade disponivel no estoque do produto selecionado com sucesso" << endl;
            continuaop6:
                cout << "Digite qual vai a nova quantidade disponivel no estoque : ";
                getchar();
                fgets(quantidade, 21, stdin);

                vefquant = true;

                for (int i = 0; i < strlen(quantidade) - 1; i++)
                    if (!isdigit(quantidade[i]))
                    {
                        vefquant = false;
                        break;
                    }

                if (vefquant)
                {
                    p[i].quantidadedisp = atoll(quantidade);
                    cout << "Alteracao da quantidade disponivel realizada com sucesso !" << endl;
                    cout << "Aperte a tecla ENTER para voltar para o menu de selecao de alterecao" << endl;
                    getchar();
                    system("clear||cls");
                    goto menuselec;
                }
                else
                {
                    cout << "-Quantidade disponivel no estoque digitada e valida-" << endl;
                selecaoop6:
                    cout << "Caso queira selecionar outra opcao digite 1, caso o contrario, digite 2 para tentar novamente : ";
                    cin >> op;
                    switch (op)
                    {
                    case 1:
                        system("clear||cls");
                        goto menuselec;
                    case 2:
                        system("cls||clear");
                        goto continuaop6;
                    default:
                        cout << "!Opcao invalida!" << endl;
                        cout << "Por favor , selecione uma opcao valida" << endl;
                        goto selecaoop6;
                    }
                }
            case 7:
                cout << "Aperte a tecla ENTER para voltar para o menu principal" << endl;
                getchar();
                getchar();
                system("clear||cls");
                return *p;
            default:
                cout << "!Opcao invalida!" << endl;
                cout << "Por favor , selecione uma opcao valida" << endl;
                goto menuselec;
            }
        }
    }
    cout << "Nao foi possivel encontrar o produto , tente novamente selecionando a opcao de Editar/Alterar" << endl;
    cout << "Aperte a tecla ENTER para prosseguir" << endl;
    getchar();
    system("clear||cls");
    return *p;
}

int strcicmp(char const *a, char const *b)
{
    for (;; a++, b++)
    {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
    }
}

void listagemtipo(produto *p)
{
    int k, l;
    produto aux;
    char busca[50];
    bool vef;
    vef = false;
    int prod = 1;
    cout << "-Opcao : Listagem por Tipo de Produto, Selecionada com Sucesso-" << endl
         << endl;
listagembuscaop:
    if (ind == 0)
    {
        cout << "Ainda nao existe produto(s) salvo no sistema , adicione algum produto e tente novamente" << endl;
    }
    else
    {
        getchar();
        cout << "Digite o tipo do produto que deseja listar : ";

        fgets(busca, 52, stdin);

        cout << "-A seguir , a listagem de todos os produtos que possui esse tipo cadastrado ate o momento-" << endl
             << endl;

        for (k = 0; k < ind; k++)
        {
            aux = p[k];
            for (l = k; (l > 0) && (strcicmp(aux.nome, p[l - 1].nome) < 0); l--)
                p[l] = p[l - 1];
            p[l] = aux;
        }

        for (int i = 0; i < ind; i++)
        {
            if (strcicmp(busca, p[i].tipo) == 0)
            {
                cout << "-------PRODUTO " << prod << "--------" << endl;
                cout << "Nome do Produto : " << p[i].nome << endl;
                cout << "Tipo do Produto : " << p[i].tipo << endl;
                cout << "Preco do Produto : R$ " << p[i].preco << endl;
                cout << "Local com Disponibilidade : " << p[i].localdisp << endl;
                cout << "Identificador : " << p[i].identificador << endl;
                cout << "Quantidade Disponivel : " << p[i].quantidadedisp << endl;
                cout << "-----------------------" << endl;
                prod++;
                vef = true;
            }
        }

        if (!vef)
        {
            cout << "-Nao foi possivel encontrar produtos com esse tipo-" << endl
                 << endl;
        }
    }
listatipoagain:
    cout << "-Deseja realizar outra busca ? Digite 1 para sim ou 2 para nao-" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        system("clear||cls");
        goto listagembuscaop;
    case 2:
        break;
    default:
        cout << "!Opcao invalida , tente novamente selecionando uma opcao valida!" << endl;
        goto listatipoagain;
    }
}

void listagempreco(produto *p)
{
    int k, l;
    produto aux;

    cout << "-A seguir , a listagem de todos os produtos cadastrado ate o momento-" << endl
         << endl;

    if (ind == 0)
    {
        cout << "Ainda nao existe produto(s) salvo no sistema , adicione algum produto e tente novamente" << endl;
    }
    else
    {
        for (k = 0; k < ind; k++)
        {
            aux = p[k];
            for (l = k; (l > 0) && (aux.preco > p[l - 1].preco); l--)
                p[l] = p[l - 1];
            p[l] = aux;
        }

        for (int i = 0; i < ind; i++)
        {
            cout << "-------PRODUTO " << i + 1 << "--------" << endl;
            cout << "Nome do Produto : " << p[i].nome << endl;
            cout << "Tipo do Produto : " << p[i].tipo << endl;
            cout << "Preco do Produto : R$ " << p[i].preco << endl;
            cout << "Local com Disponibilidade : " << p[i].localdisp << endl;
            cout << "Identificador : " << p[i].identificador << endl;
            cout << "Quantidade Disponivel : " << p[i].quantidadedisp << endl;
            cout << "-----------------------" << endl;
        }
    }
}

void listagemlocal(produto *p)
{
    int k, l;
    produto aux;
    char busca[50];
    bool vef;
    vef = false;
    int prod = 1;
    cout << "-Opcao : Listagem por Local de Produto, Selecionada com Sucesso-" << endl
         << endl;
listagembuscaop:
    if (ind == 0)
    {
        cout << "Ainda nao existe produto(s) salvo no sistema , adicione algum produto e tente novamente" << endl;
    }
    else
    {
        getchar();
        cout << "Digite o local que deseja listar os produtos disponiveis: ";

        fgets(busca, 52, stdin);

        cout << "-A seguir , a listagem de todos os produtos ate o momento no local desejado-" << endl
             << endl;

        for (k = 0; k < ind; k++)
        {
            aux = p[k];
            for (l = k; (l > 0) && (strcicmp(aux.nome, p[l - 1].nome) < 0); l--)
                p[l] = p[l - 1];
            p[l] = aux;
        }

        for (int i = 0; i < ind; i++)
        {
            if (strcicmp(busca, p[i].localdisp) == 0)
            {
                cout << "-------PRODUTO " << prod << "--------" << endl;
                cout << "Nome do Produto : " << p[i].nome << endl;
                cout << "Tipo do Produto : " << p[i].tipo << endl;
                cout << "Preco do Produto : R$ " << p[i].preco << endl;
                cout << "Local com Disponibilidade : " << p[i].localdisp << endl;
                cout << "Identificador : " << p[i].identificador << endl;
                cout << "Quantidade Disponivel : " << p[i].quantidadedisp << endl;
                cout << "-----------------------" << endl;
                prod++;
                vef = true;
            }
        }

        if (!vef)
        {
            cout << "-Nao foi possivel encontrar produtos no local desejado-" << endl
                 << endl;
        }
    }
listatipoagain:
    cout << "-Deseja realizar outra busca ? Digite 1 para sim ou 2 para nao-" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        system("clear||cls");
        goto listagembuscaop;
    case 2:
        break;
    default:
        cout << "!Opcao invalida , tente novamente selecionando uma opcao valida!" << endl;
        goto listatipoagain;
    }
}

void menulista(produto *p)
{
    if (ind == 0)
    {
        cout << "Ainda nao existe produto(s) salvo no sistema , adicione algum produto e tente novamente" << endl;
    }
    else
    {
    iniciolist:
        cout << "Bem vindo ao menu de listagem , escolhe entre 1 e 5 para as seguintes opcoes de listagem : " << endl
             << "1. Listar tudo em ordem alfabetica" << endl
             << "2. Listar tudo por preco" << endl
             << "3. Listar de acordo por tipo do produto" << endl
             << "4. Listar de acordo com o local de disponibilidade do produto" << endl
             << "5. Sair do menu de listagem" << endl
             << endl;

        cin >> op;
        switch (op)
        {
        case 1:
            system("clear||cls");
            cout << "-Opcao : Listagem dos Produtos em Ordem Alfabetica , Selecionada com Sucesso-" << endl
                 << endl;
            listagem(p);
            cout << "-Aperte a tecla ENTER para voltar ao menu principal-" << endl;
            getchar();
            getchar();
            system("clear||cls");
            goto iniciolist;
        case 2:
            system("clear||cls");
            cout << "-Opcao : Listagem dos Produtos de Acordo com o Preco , Selecionada com Sucesso" << endl
                 << endl;
            listagempreco(p);
            cout << "-Aperte a tecla ENTER para voltar ao menu principal-" << endl;
            getchar();
            getchar();
            system("clear||cls");
            goto iniciolist;
        case 3:
            system("clear||cls");
            listagemtipo(p);
            getchar();
            system("clear||cls");
            goto iniciolist;
        case 4:
            system("clear||cls");
            listagemlocal(p);
            getchar();
            system("clear||cls");
            goto iniciolist;
        case 5:
            break;
        default:
            cout << "!Opcao invalida!" << endl;
            cout << "Por favor , selecione uma opcao valida" << endl;
            goto iniciolist;

        }
    }
    cout << "-Aperte a tecla ENTER para continuar-" << endl;
    getchar();
}