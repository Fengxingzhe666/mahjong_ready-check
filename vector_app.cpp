// vector_app.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>
#include<algorithm>//包含sort()函数
#include<unordered_map>
#include "check_win.h"
#include <set>
#include<ctype.h>
#include<string>

using namespace std;

void displayMatrix(const std::vector<std::vector<int>>& matrix) 
{ 
    for (const auto& row : matrix) 
    { 
        for (int val : row) 
        { 
            std::cout << val << " "; 
        } 
        std::cout << std::endl; 
    } 
}

std::vector<std::vector<int>> every_subset_gpt(std::vector<int> x, int n, bool f) {
    std::vector<std::vector<int>> subsets;

    // 排序以便后续处理重复
    std::sort(x.begin(), x.end());

    // 使用 next_permutation 枚举 n 组合
    std::vector<bool> mask(x.size(), false);
    std::fill(mask.begin(), mask.begin() + n, true); // 前 n 个位置置为 true

    do {
        std::vector<int> subset;
        for (size_t i = 0; i < x.size(); ++i) {
            if (mask[i]) {
                subset.push_back(x[i]);
            }
        }
        subsets.push_back(subset);
    } while (std::prev_permutation(mask.begin(), mask.end()));

    // 如果需要去重
    if (f) {
        std::set<std::vector<int>> unique_subsets(subsets.begin(), subsets.end());
        subsets.assign(unique_subsets.begin(), unique_subsets.end());
    }
    return subsets;
}

std::vector<int> Transform_string_to_int_vector(std::string input)
{
    std::vector<int> temp;
    std::vector<int> results;
    for (int i = 0;i < input.size();i++)
    {
        if (isdigit(input[i]))
        {
            //如果是数字，将input[i]添加到temp的末尾
            temp.push_back(input[i] - '0');
        }
        else
        {
            switch (input[i])
            {
            case 'm':
                results.insert(results.end(), temp.begin(), temp.end());
                break;
            case 'p':
                for (int j = 0;j < temp.size();j++)
                {
                    temp[j] += 9;
                }
                results.insert(results.end(), temp.begin(), temp.end());
                break;
            case 's':
                for (int j = 0;j < temp.size();j++)
                {
                    temp[j] += 18;
                }
                results.insert(results.end(), temp.begin(), temp.end());
                break;
            case 'z':
                for (int j = 0;j < temp.size();j++)
                {
                    temp[j] += 27;
                }
                results.insert(results.end(), temp.begin(), temp.end());
                break;
            default:
                throw "Invalid characters detected!";
                break;
            }
            temp.clear();
        }
    }
    return results;
}

int main()
{
    Check_Win c1;
    std::string a="";
    std::string b = "";
    while (true)
    {
        cin >> a;
        if (a != "q" && a != "Q")
        {
            c1.v_13 = Transform_string_to_int_vector(a);
            vector<string> ready = c1.check_if_ready();
            //Display the contents of matched_combo
            std::cout << "ready: ";
            for (int i = 0; i < ready.size(); i++)
            {
                std::cout << ready[i] << " ";
            }
            std::cout << endl;
            cin >> b;
            vector<int> b_vec = Transform_string_to_int_vector(b);
            c1.v_14 = c1.v_13;
            c1.v_14.insert(c1.v_14.end(),b_vec.begin(), b_vec.end());
            c1.check_if_win();
            for (const auto& row : c1.win_group)
            {
                for (int val : row)
                {
                    std::cout << c1.tileMapping.at(val) << " ";
                }
                std::cout << std::endl;
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}