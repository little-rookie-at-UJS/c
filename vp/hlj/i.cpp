//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'

//struct cha {
//    cha *pre;
//    cha *nex;
//    char c;
//
//    cha(char ca) {
//        c = ca;
//        pre = nullptr;
//        nex = nullptr;
//
//    }
//};
//
//bool check(cha *link) {
//
//    char a = link->c;
//    if (!link->nex)return false;
//    link = link->nex;
//    char b = link->c;
//    if (!link->nex)return false;
//    link = link->nex;
//    char c = link->c;
//    return a == b && b == c;
//}
//
//void del(cha *link) {
//    cha *pre = link->pre;
//    cha *nex = link->nex->nex->nex;
//    pre->nex = nex;
//
//    nex->pre = pre;
//}
//
//cha *run(cha *link) {
//    if (link->c == '!')return nullptr;
//    if (link->pre->c != '!')return link->pre;
//    return link;
//}

void run(deque<char> &st) {
    if (st.size() < 3)return;
    auto a = st.back();
    st.pop_back();
    auto b = st.back();
    st.pop_back();
    auto c = st.back();
    st.pop_back();
    if (a == b && b == c)return;
    st.emplace_back(c);
    st.emplace_back(b);
    st.emplace_back(a);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    deque<char> st;
    string s;
    cin >> s;
    for (auto i: s) {
        st.emplace_back(i);
        run(st);
    }
    if (!st.empty()) {
        while (!st.empty()) {
            cout << char(st.front());
            st.pop_front();
        }
    } else {
        cout << "NAN";
    }

//    cha *head = new cha('!');
//    string s;
//    cin >> s;
//    cha *back = head;
//    for (auto i: s) {
//        cha *nex = new cha(i);
//        back->nex = nex;
//        nex->pre = back;
//        back = nex;
//    }
//    back->nex = new cha('#');
//    back->nex->pre = back;
//    cha *now = head->nex;
//    while (now) {
//        if (check(now)) {
//            del(now);
//            now = run(now->pre);
//        } else {
//            now = now->nex;
//        }
//    }
//    if (head->nex->c != '#') {
//        cha *now = head->nex;
//        while (now->c!='#') {
//            cout << now->c;
//            now = now->nex;
//        }
//    } else {
//        cout << "NaN";
//    }
}

