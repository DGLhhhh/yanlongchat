#include "global.h"

QString gate_url_prefix = "";

// 将全局对象赋值给repolish
std::function<void(QWidget*)> repolish = [](QWidget* w){
    w->style()->unpolish(w);
    w->style()->polish(w);
};
