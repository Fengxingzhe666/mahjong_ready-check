//check_win.cpp
#include <iostream>
#include <vector>
#include<algorithm>//包含sort()函数
#include<unordered_map>
#include"check_win.h"

bool Check_Win::check_if_win()
{
	//函数定义写在这儿
    std::sort(v_14.begin(), v_14.end());
    win_state = false;
    for (int i = 0;i < combo.size();i++)
    {
        for (int j = 0;j < is_subset(combo[i], v_14);j++)
        {
            matched_combo.push_back(i);
        }
    }
    for (int i = 0;i < tile_pair.size();i++)
    {
        for (int j = 0;j < is_subset(tile_pair[i], v_14);j++)
        {
            matched_pair.push_back(i);
        }
    }
    if (matched_combo.size() >= combo_num)
    {
        ax = every_subset(matched_combo, combo_num, true);
        std::vector<int> ay;
        for (int i = 0;i < ax.size();i++, ay.clear())
        {
            for (int j = 0;j < combo_num;j++)
            {
                ay.insert(ay.end(), combo[ax[i][j]].begin(), combo[ax[i][j]].end());
            }
            std::sort(ay.begin(), ay.end());
            if (is_subset(ay, v_14) > 0)
            {
                std::vector<int> ay2;
                for (int k = 0;k < tile_pair.size();k++)
                {
                    ay2 = ay;
                    ay2.insert(ay2.end(), tile_pair[k].begin(), tile_pair[k].end());
                    if (is_subset(ay2, v_14) > 0)
                    {
                        //匹配成功
                        win_group[0] = combo[ax[i][0]];
                        win_group[1] = combo[ax[i][1]];
                        win_group[2] = combo[ax[i][2]];
                        win_group[3] = combo[ax[i][3]];
                        win_group[4] = tile_pair[k];
                        win_state = true;
                        break;
                    }
                }
            }
        }
    }
    else 
    {
        return false;
    }
    //调用完要把matched_combo清空，否则下次调用会再下边继续累加，运行时间指数增长
    matched_combo.clear();
    //win_state = win_group[0][0] != 0;
    return win_state;
}

std::vector<std::string> Check_Win::check_if_ready()
{
    if (v_13.size() != 13)
    {
        if (v_13.size() == 10)
        {
            for (int item = 0;item < 3;item++)
                v_13.push_back(35);
        }
        else if (v_13.size() == 7)
        {
            for (int item = 0;item < 3;item++)
            {
                v_13.push_back(35);
                v_13.push_back(36);
            }   
        }
        else if (v_13.size() == 4)
        {
            for (int item = 0;item < 3;item++)
            {
                v_13.push_back(35);
                v_13.push_back(36);
                v_13.push_back(37);
            }  
        }
        else if (v_13.size() == 1)
        {
            for (int item = 0;item < 3;item++)
            {
                v_13.push_back(35);
                v_13.push_back(36);
                v_13.push_back(37);
                v_13.push_back(38);
            }
        }
        else
        {
            throw "Ready state: error v_13 elements numbers";
        }
    }
    std::vector<int> vo ;
    std::vector<std::string> vo_str;
    for (int i = 1;i <= combo.size();i++)
    {
        v_14 = v_13;
        v_14.push_back(i);
        check_if_win();
        if (win_state)
        {
            vo.push_back(i);
            win_group = { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0} };
        }
    }
    for (int i = 0;i < vo.size();i++)
        vo_str.push_back(tileMapping.at(vo[i]));
    return vo_str;
}
int Check_Win::is_subset(std::vector<int> x, std::vector<int> y)
{
    //判断x是否为y的一个子集，返回int值表示y中最多包含多少个x，当x不为y子集时返回0
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    std::vector<int> x0 = x;
    int results;
    for (results = 0;;results++)
    {
        if (std::includes(y.begin(), y.end(), x0.begin(), x0.end()))
        {
            //匹配成功，x复制一份，进行下一次匹配
            x0.insert(x0.end(), x.begin(), x.end());
            std::sort(x0.begin(), x0.end());
        }
        else
        {
            break;//匹配失败，跳出循环并返回int值
        }
    }
    return results;
}
long long Check_Win:: C(int n, int m)
{
    //计算排列组合数C(n,m),前提条件：n>=m
    long long res = 1;
    m = std::min(m, n - m);
    for (int i = 0; i < m; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
std::vector<std::vector<int>> Check_Win::every_subset(std::vector<int> x, int n,bool f)
{
    //返回一个二维vector，枚举表示x中的每一种包含n个元素的子集，f表示是否去除重复组
    std::vector<int> temp(n);
    std::vector<std::vector<int>> results(C(x.size(), n), std::vector<int>(n));
    int jto = 0;
    for (int i = 0; i < n; i++)
    {
        temp[i] = i;
    }
    while (true)
    {
        for (int j = 0;j < n;j++)
        {
            results[jto][j] = x[temp[j]];//保存结果
            //results[jto]={x[temp[0]],x[temp[1]],......,x[temp[n-1]]}           
        }
        if (temp[0] >= x.size() - n)
        {
            break;
        }
        jto++;
        temp[n - 1]++;
        if (temp[n - 1] > x.size() - 1)
        {
            for (int l_idx = n - 2;l_idx >= 0;l_idx--)
            {
                if (temp[l_idx] < l_idx + x.size() - n)
                {
                    temp[l_idx]++;
                    for (int i = 0;l_idx + i < n;i++)
                    {
                        temp[l_idx + i] = temp[l_idx] + i;
                    }
                    break;
                }
            }
        }
    }
    if (f)
    {
        auto last = std::unique(results.begin(), results.end());
        results.erase(last, results.end());
    }
    return results;
}