#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    char color;
    struct node *l,*r,*p;
};

struct node *root=NULL;

struct node* new(int d)
{
    struct node* t=malloc(sizeof(struct node));
    t->data=d;
    t->color='R';
    t->l=t->r=t->p=NULL;
    return t;
}

void ll(struct node *x)
{
    struct node *y=x->r;
    x->r=y->l;
    if(y->l)
        y->l->p=x;
    y->p=x->p;
    if(!x->p)
        root=y;
    else if(x==x->p->l)
        x->p->l=y;
    else
        x->p->r=y;
    y->l=x;
    x->p=y;
}

void rr(struct node *x)
{
    struct node *y=x->l;
    x->l=y->r;
    if(y->r)
        y->r->p=x;
    y->p=x->p;
    if(!x->p)
        root=y;
    else if(x==x->p->r)
        x->p->r=y;
    else
        x->p->l=y;
    y->r=x;
    x->p=y;
}

void fix_insert(struct node *z)
{
    while(z->p && z->p->color=='R')
    {
        if(z->p==z->p->p->l)
        {
            struct node *y=z->p->p->r;
            if(y && y->color=='R')
            {
                z->p->color='B';
                y->color='B';
                z->p->p->color='R';
                z=z->p->p;
            }
            else
            {
                if(z==z->p->r)
                {
                    z=z->p;
                    ll(z);
                }
                z->p->color='B';
                z->p->p->color='R';
                rr(z->p->p);
            }
        }
        else
        {
            struct node *y=z->p->p->l;
            if(y && y->color=='R')
            {
                z->p->color='B';
                y->color='B';
                z->p->p->color='R';
                z=z->p->p;
            }
            else
            {
                if(z==z->p->l)
                {
                    z=z->p;
                    rr(z);
                }
                z->p->color='B';
                z->p->p->color='R';
                ll(z->p->p);
            }
        }
    }
    root->color='B';
}

void insert(int d)
{
    struct node *z=new(d),*y=NULL,*x=root;

    while(x)
    {
        y=x;
        if(d<x->data)
            x=x->l;
        else
            x=x->r;
    }

    z->p=y;
    if(!y)
        root=z;
    else if(d<y->data)
        y->l=z;
    else
        y->r=z;

    fix_insert(z);
}

struct node* min(struct node *x)
{
    while(x->l)
        x=x->l;
    return x;
}

void fix_delete(struct node *x)
{
    while(x!=root && (!x || x->color=='B'))
    {
        if(x==x->p->l)
        {
            struct node *w=x->p->r;
            if(w && w->color=='R')
            {
                w->color='B';
                x->p->color='R';
                ll(x->p);
                w=x->p->r;
            }
            if((!w->l || w->l->color=='B') && (!w->r || w->r->color=='B'))
            {
                w->color='R';
                x=x->p;
            }
            else
            {
                if(!w->r || w->r->color=='B')
                {
                    w->l->color='B';
                    w->color='R';
                    rr(w);
                    w=x->p->r;
                }
                w->color=x->p->color;
                x->p->color='B';
                if(w->r)
                    w->r->color='B';
                ll(x->p);
                x=root;
            }
        }
        else
        {
            struct node *w=x->p->l;
            if(w && w->color=='R')
            {
                w->color='B';
                x->p->color='R';
                rr(x->p);
                w=x->p->l;
            }
            if((!w->r || w->r->color=='B') && (!w->l || w->l->color=='B'))
            {
                w->color='R';
                x=x->p;
            }
            else
            {
                if(!w->l || w->l->color=='B')
                {
                    w->r->color='B';
                    w->color='R';
                    ll(w);
                    w=x->p->l;
                }
                w->color=x->p->color;
                x->p->color='B';
                if(w->l)
                    w->l->color='B';
                rr(x->p);
                x=root;
            }
        }
    }
    if(x)
        x->color='B';
}

void delete(int d)
{
    struct node *z=root,*y,*x;

    while(z && z->data!=d)
        if(d<z->data)
            z=z->l;
        else
            z=z->r;

    if(!z)
        return;

    y=z;
    char yc=y->color;

    if(!z->l)
    {
        x=z->r;
        if(z->p)
        {
            if(z==z->p->l)
                z->p->l=z->r;
            else
                z->p->r=z->r;
        }
        if(z->r)
            z->r->p=z->p;
    }
    else if(!z->r)
    {
        x=z->l;
        if(z->p)
        {
            if(z==z->p->l)
                z->p->l=z->l;
            else
                z->p->r=z->l;
        }
        if(z->l)
            z->l->p=z->p;
    }
    else
    {
        y=min(z->r);
        yc=y->color;
        x=y->r;
        if(y->p==z)
        {
            if(x)
                x->p=y;
        }
        else
        {
            if(y->p)
            {
                if(y==y->p->l)
                    y->p->l=y->r;
                else
                    y->p->r=y->r;
            }
            if(y->r)
                y->r->p=y->p;
            y->r=z->r;
            y->r->p=y;
        }
        if(z->p)
        {
            if(z==z->p->l)
                z->p->l=y;
            else
                z->p->r=y;
        }
        y->p=z->p;
        y->l=z->l;
        y->l->p=y;
        y->color=z->color;
    }

    if(yc=='B')
        fix_delete(x);
}

int main()
{
    int n,i,x,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        insert(x);
    }
    scanf("%d",&m);
    delete(m);
    return 0;
}
