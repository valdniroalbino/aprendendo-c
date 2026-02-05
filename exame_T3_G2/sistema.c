#include "sistema.h"
#include <string.h>

/* ================= ELEITORES ================= */

Eleitor *criarEleitor(int id,const char *nome){
    Eleitor *novo=malloc(sizeof(Eleitor));
    if(!novo)return NULL;
    novo->id=id;
    strncpy(novo->nome,nome,99);
    novo->nome[99]='\0';
    novo->votou=0;
    novo->prox=NULL;
    return novo;
}

void inserirEleitor(Eleitor **lista,Eleitor *novo){
    if(!novo)return;
    if(!*lista){
        *lista=novo;
        return;
    }
    Eleitor *aux=*lista;
    while(aux->prox)aux=aux->prox;
    aux->prox=novo;
}

Eleitor *procurarEleitor(Eleitor *lista,int id){
    while(lista){
        if(lista->id==id)return lista;
        lista=lista->prox;
    }
    return NULL;
}

int idExiste(Eleitor *lista,int id){
    return procurarEleitor(lista,id)!=NULL;
}

void atualizarEleitor(Eleitor *lista,int id,const char *novoNome){
    Eleitor *e=procurarEleitor(lista,id);
    if(e){
        strncpy(e->nome,novoNome,99);
        e->nome[99]='\0';
    }
}

void jaVotou(Eleitor *e){
    if(e)e->votou=1;
}

void imprimirEleitores(Eleitor *lista){
    while(lista){
        printf("ID:%d | Nome:%s | Votou:%s\n",
               lista->id,lista->nome,lista->votou?"Sim":"Nao");
        lista=lista->prox;
    }
}

void carregarEleitoresFicheiro(Eleitor **lista,const char *nomeFicheiro){
    FILE *f=fopen(nomeFicheiro,"r");
    if(!f){printf("Erro ao abrir ficheiro.\n");return;}

    int id,votou;
    char nome[100];

    while(fscanf(f,"%99s %d %d",nome,&id,&votou)==3){
        Eleitor *e=criarEleitor(id,nome);
        if(e){
            e->votou=votou;
            inserirEleitor(lista,e);
        }
    }
    fclose(f);
}

void libertarEleitores(Eleitor **lista){
    Eleitor *aux;
    while(*lista){
        aux=*lista;
        *lista=(*lista)->prox;
        free(aux);
    }
}

/* ================= CANDIDATOS ================= */

int inserirCandidato(Candidato **lista,int id,char nome[]){
    if(procurarCandidato(*lista,id))return 0;
    Candidato *c=malloc(sizeof(Candidato));
    if(!c)return 0;
    c->id=id;
    strncpy(c->nome,nome,49);
    c->nome[49]='\0';
    c->votos=0;
    c->prox=*lista;
    *lista=c;
    return 1;
}

Candidato *procurarCandidato(Candidato *lista,int id){
    while(lista){
        if(lista->id==id)return lista;
        lista=lista->prox;
    }
    return NULL;
}

int removerCandidato(Candidato **lista,int id){
    Candidato *ant=NULL,*atual=*lista;
    while(atual&&atual->id!=id){
        ant=atual;
        atual=atual->prox;
    }
    if(!atual)return 0;
    if(!ant)*lista=atual->prox;
    else ant->prox=atual->prox;
    free(atual);
    return 1;
}

void imprimirCandidatos(Candidato *lista){
    while(lista){
        printf("ID:%d | Nome:%s | Votos:%d\n",
               lista->id,lista->nome,lista->votos);
        lista=lista->prox;
    }
}

void carregarCandidatosFicheiro(Candidato **lista,const char *nomeFicheiro){
    FILE *f=fopen(nomeFicheiro,"r");
    if(!f){printf("Erro ao abrir ficheiro.\n");return;}

    int id;
    char nome[50];
    while(fscanf(f,"%d %49s",&id,nome)==2){
        inserirCandidato(lista,id,nome);
    }
    fclose(f);
}

void libertarCandidatos(Candidato **lista){
    Candidato *aux;
    while(*lista){
        aux=*lista;
        *lista=(*lista)->prox;
        free(aux);
    }
}

/* ================= FILAS ================= */

void iniciarFila(Fila *fila){
    fila->ini=NULL;
    fila->fim=NULL;
    fila->tam=0;
}

int inserirFila(Fila *fila,int id,char nome[]){
    NoFila *n=malloc(sizeof(NoFila));
    if(!n)return 0;
    n->idEle=id;
    strncpy(n->nome,nome,49);
    n->nome[49]='\0';
    n->prox=NULL;

    if(fila->fim)fila->fim->prox=n;
    else fila->ini=n;

    fila->fim=n;
    fila->tam++;
    return 1;
}

int removerFila(Fila *fila){
    if(!fila->ini)return 0;
    NoFila *aux=fila->ini;
    fila->ini=aux->prox;
    if(!fila->ini)fila->fim=NULL;
    free(aux);
    fila->tam--;
    return 1;
}

int desistirFila(Fila *fila,int id){
    NoFila *ant=NULL,*at=fila->ini;
    while(at&&at->idEle!=id){
        ant=at;
        at=at->prox;
    }
    if(!at)return 0;
    if(!ant)fila->ini=at->prox;
    else ant->prox=at->prox;
    if(at==fila->fim)fila->fim=ant;
    free(at);
    fila->tam--;
    return 1;
}

void imprimirFila(Fila *fila){
    NoFila *aux=fila->ini;
    while(aux){
        printf("ID:%d | Nome:%s\n",aux->idEle,aux->nome);
        aux=aux->prox;
    }
}

int tamanhoFila(Fila *fila){return fila->tam;}

void libertarFila(Fila *fila){
    while(fila->ini)removerFila(fila);
}

/* ================= PILHA ================= */

void criarPilha(Pilha *pilha){pilha->topo=NULL;}
int pilhaVazia(Pilha *pilha){return pilha->topo==NULL;}

void empilhar(Pilha *pilha,Voto voto){
    NoPilha *n=malloc(sizeof(NoPilha));
    if(!n)return;
    n->voto=voto;
    n->prox=pilha->topo;
    pilha->topo=n;
}

Voto desempilhar(Pilha *pilha){
    Voto v={0};
    if(pilhaVazia(pilha))return v;
    NoPilha *aux=pilha->topo;
    v=aux->voto;
    pilha->topo=aux->prox;
    free(aux);
    return v;
}

void libertarPilha(Pilha *pilha){
    while(!pilhaVazia(pilha))desempilhar(pilha);
}

/* ================= RESULTADOS ================= */

void iniciarVotacao(Resultado *r){
    r->validos=0;
    r->brancos=0;
    r->nulos=0;
}

void processarVoto(Resultado *r,Pilha *auditoria,Voto voto){
    empilhar(auditoria,voto);
    if(voto.idCandidato>0)r->validos++;
    else if(voto.idCandidato==0)r->brancos++;
    else r->nulos++;
}

void mostrarResultadosParciais(Resultado *r){
    printf("Validos:%d Brancos:%d Nulos:%d\n",r->validos,r->brancos,r->nulos);
}

void mostrarResultadoFinal(Resultado *r,Candidato *c){
    imprimirCandidatos(c);
    mostrarResultadosParciais(r);

    if(!c)return;

    Candidato *vencedor=c,*aux=c;
    int empate=0;

    while(aux){
        if(aux->votos>vencedor->votos){
            vencedor=aux;
            empate=0;
        }else if(aux!=vencedor && aux->votos==vencedor->votos){
            empate=1;
        }
        aux=aux->prox;
    }

    if(vencedor->votos==0)
        printf("Sem vencedor.\n");
    else if(empate)
        printf("Empate com %d votos.\n",vencedor->votos);
    else
        printf("VENCEDOR: %s (%d)\n",vencedor->nome,vencedor->id);
}

void gerarFicheiroFinal(Resultado *r,Candidato *c,int total){
    FILE *f=fopen("resultado_final.txt","w");
    if(!f)return;

    fprintf(f,"Total eleitores:%d\n",total);
    fprintf(f,"Validos:%d Brancos:%d Nulos:%d\n",
            r->validos,r->brancos,r->nulos);

    Candidato *v=c,*vencedor=NULL;
    while(v){
        fprintf(f,"%s (%d): %d votos\n",v->nome,v->id,v->votos);
        if(!vencedor||v->votos>vencedor->votos)
            vencedor=v;
        v=v->prox;
    }

    if(vencedor && vencedor->votos>0)
        fprintf(f,"VENCEDOR: %s (%d)\n",vencedor->nome,vencedor->id);

    fclose(f);
}