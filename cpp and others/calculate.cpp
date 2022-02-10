#include "calculate.h"

calculate::calculate()
{

}
void calculate::dev_and_mult(double& result,std::list<std::string>& sep,int& check)
{
    for (auto i = sep.begin(); i != sep.end(); i++)
    {
        double temp;
        switch ((*i)[0])
        {
        case '/':
            result = atof((*(--i)).c_str());
            ++i;
            temp = atof((*(++i)).c_str());
            if (!temp)
            {
                check=1;
                break;
            }
            result /= temp;
            *i = std::to_string(result);
            --i;
            sep.erase(i--);
            sep.erase(i++);
            break;
        case '*':
            result = atof((*(--i)).c_str());
            ++i;
            result *= atof((*(++i)).c_str());
            *i = std::to_string(result);
            --i;
            sep.erase(i--);
            sep.erase(i++);
            break;
        case '=':
            if(result == 0)
                result+=atof((*(--i)).c_str());
            break;
       /* case '%':
            result = atof((*(--i)).c_str());
            ++i;
            result %= atof((*(++i)).c_str());
            *i = std::to_string(result);
            --i;
            sep.erase(i--);
            sep.erase(i++);
            break;*/
        default:
            break;
        }
    }
}
void calculate::calculate_this(double& result, std::string operation,int& check)
{
    std::list<std::string > sep;
    separation(operation, sep);
   /* for (auto i : sep)
        std::cerr << i << " ";*/
    dev_and_mult(result, sep, check);
    sum_and_substr(result, sep);
}
void calculate::sum_and_substr(double& result, std::list<std::string>& sep)
{
    for (auto i = sep.begin(); i != sep.end(); i++)
    {

        switch ((*i)[0])
        {
        case '+':

            result = atof((*(--i)).c_str());
            ++i;
            result += atof((*(++i)).c_str());
            *i = std::to_string(result);
            break;
        case '-':
            result = atof((*(--i)).c_str());
            ++i;
            result -= atof((*(++i)).c_str());
            *i = std::to_string(result);
            break;
        default:
            break;
        }
    }
}
void calculate::separation(std::string operation, std::list<std::string>& sep)
{
    sep.push_back("");
    auto iter_sep = sep.begin();
    for (auto it : operation)
    {
        if ((it == '+') || (it == '-') || (it == '/') || (it == '*')||(it=='%')||(it=='^'))
        {
            sep.push_back("");
            ++iter_sep;
            *iter_sep = it;
            sep.push_back("");
            ++iter_sep;
            continue;
        }
        if (it == '=')
        {
            sep.push_back("=");
            break;
        }
        else
            *iter_sep += it;
    }
}
