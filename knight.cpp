#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue)
{
    cout << "HP=" << HP
         << ", level=" << level
         << ", remedy=" << remedy
         << ", maidenkiss=" << maidenkiss
         << ", phoenixdown=" << phoenixdown
         << ", rescue=" << rescue << endl;
}

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    // Xu li dau vao
    ifstream fin1;
    fin1.open(file_input.c_str());

    string dong1, dong2, dong3;
    getline(fin1, dong1);
    getline(fin1, dong2);
    getline(fin1, dong3);
    fin1.close();

    stringstream ss(dong1);
    ss >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    rescue = -1;
    int maxHP = HP;
    int damagedHP;
    int dem = 0;
    bool shaman = 0;
    bool siren = 0;
    bool merlin = 0;
    bool asclepius = 0;
    int event[100];
    int exlevel;
    for (int i = 0; i < dong2.size(); i++)
    {
        if (dong2[i] == ' ' && dong2[i + 1] != ' ')
            dem++;
    }
    stringstream s(dong2);

    for (int i = 0; i < dem + 1; i++)
    {
        s >> event[i];
    }
    stringstream sss(dong3);
    string file_mush_ghost;
    getline(sss, file_mush_ghost, ',');
    string file_asclepius_pack;
    getline(sss, file_asclepius_pack, ',');
    string file_merlin_pack;
    getline(sss, file_merlin_pack);

    // Thuc hien ma su kien
    if (maxHP != 999 && !isPrime(maxHP))
    {
        for (int i = 0; i < dem + 1; i++)
        {

            if (i == dem)
            {
                rescue = 1;
            }
            // ma 15 nhat remedy
            if (event[i] == 15)
            {
                if (event[i - 3] == 7 && siren == 1)
                {
                    level = exlevel;
                    siren = 0;
                }
                if (remedy == 0)
                {
                    remedy++;
                    if (shaman == 1)
                    {
                        HP = HP * 5;
                        remedy--;
                        shaman = 0;
                    }
                    else
                        HP;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if (remedy < 99 && remedy > 0)
                {
                    remedy++;

                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // ma 16 nhat maidenkiss
            else if (event[i] == 16)
            {
                if (event[i - 3] == 6 && shaman == 1)
                {
                    HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                    shaman = 0;
                }
                if (maidenkiss == 0)
                {
                    maidenkiss++;
                    if (siren == 1)
                    {
                        maidenkiss--;
                        level = exlevel;
                        siren = 0;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    else
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if (maidenkiss < 99 && maidenkiss > 0)
                {
                    maidenkiss++;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // ma 17 nhat phoenixdown
            else if (event[i] == 17)
            {
                if (event[i - 3] == 7 && siren == 1)
                {
                    level = exlevel;
                    siren = 0;
                }
                if (event[i - 3] == 6 && shaman == 1)
                {
                    HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                    shaman = 0;
                }
                if (phoenixdown < 99 && phoenixdown >= 0)
                {
                    phoenixdown++;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // ma 12 HP ha den fibonaci gan nhat
            else if (event[i] == 12)
            {
                int a = 0, b = 1, c = 1;
                while (c < HP)
                {
                    a = b;
                    b = c;
                    c = a + b;
                }

                int Fib = b;
                if (HP > 1)
                {
                    HP = Fib;
                }
                else
                {
                    HP = 1;
                }
                if (event[i - 3] == 7 && siren == 1)
                {
                    level = exlevel;
                    siren = 0;
                }
                if (event[i - 3] == 6 && shaman == 1)
                {
                    HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                    shaman = 0;
                }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // ma 11 hp tang den so nguyen to gan nhat
            else if (event[i] == 11)
            {
                int n1 = ((level + phoenixdown) % 5 + 1) * 3;
                int s1 = n1 * ((2 * 99) + (n1 - 1) * (-2)) / 2;
                HP = HP + (s1 % 100);
                if (isPrime(HP))
                {
                    HP++;
                }
                else
                {
                    for (int j = HP + 1; j <= 999; j++)
                    {
                        if (isPrime(j))
                        {
                            HP = j;
                            break;
                        }
                    }
                }
                if (HP > maxHP)
                {
                    HP = maxHP;
                }
                if (event[i - 3] == 7 && siren == 1)
                {
                    level = exlevel;
                    siren = 0;
                }
                if (event[i - 3] == 6 && shaman == 1)
                {
                    HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                    shaman = 0;
                }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // ma 0 giai cuu
            else if (event[i] == 0)
            {
                if (event[i - 3] == 7 && siren == 1)
                {
                    level = exlevel;
                    siren = 0;
                }
                if (event[i - 3] == 6 && shaman == 1)
                {
                    HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                    shaman = 0;
                }
                rescue = 1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
            else if (event[i] > 0 && event[i] < 6) // danh quai
            {
                int b = (i + 1) % 10;
                int levelO;
                levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
                float baseDamage;
                if (event[i] == 1)
                {
                    baseDamage = 1;
                }
                else if (event[i] == 2)
                {
                    baseDamage = 1.5;
                }
                else if (event[i] == 3)
                {
                    baseDamage = 4.5;
                }
                else if (event[i] == 4)
                {
                    baseDamage = 7.5;
                }
                else if (event[i] == 5)
                {
                    baseDamage = 9.5;
                }
                int damage = baseDamage * levelO * 10;

                if (levelO == level)
                {
                    if (event[i - 3] == 7 && siren == 1)
                    {
                        level = exlevel;
                        siren = 0;
                    }
                    if (event[i - 3] == 6 && shaman == 1)
                    {
                        HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                        shaman = 0;
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else if (level > levelO)
                {

                    level = (level > 9) ? 10 : level + 1;
                    if (event[i - 3] == 7 && siren == 1)
                    {
                        level = exlevel;
                        siren = 0;
                    }
                    if (event[i - 3] == 6 && shaman == 1)
                    {
                        HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                        shaman = 0;
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else

                {

                    HP = HP - damage;
                    if (HP <= 0 && phoenixdown == 0)
                    {

                        rescue = 0;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        break;
                    }
                    else if (HP <= 0 && phoenixdown > 0)
                    {
                        if (shaman == 1)
                        {
                            shaman = 0;
                        }
                        if (siren == 1)
                        {

                            siren = 0;
                            level = exlevel;
                        }
                        phoenixdown--;
                        HP = maxHP;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    else
                    {
                        if (event[i - 3] == 7 && siren == 1)
                        {
                            level = exlevel;
                            siren = 0;
                        }
                        if (event[i - 3] == 6 && shaman == 1)
                        {
                            HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                            shaman = 0;
                        }
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                }
            }

            // ma 6
            else if (event[i] == 6)
            {
                if (shaman == 1 || siren == 1)
                {
                    if (event[i - 3] == 7 && siren == 1)
                    {
                        level = exlevel;
                        siren = 0;
                    }
                    if (event[i - 3] == 6 && shaman == 1)
                    {
                        HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                        shaman = 0;
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                {
                    int b = (i + 1) % 10;
                    int levelO;
                    levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
                    if (levelO == level)
                    {
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    if (level > levelO)
                    {
                        level = (level + 2 > 9) ? 10 : level + 2;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    if (level < levelO)
                    {
                        if (remedy > 0)
                        {
                            remedy--;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        }
                        else
                        {
                            if (HP < 5)
                            {
                                HP = 1;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            }
                            else
                            {
                                HP = HP / 5;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            }
                            shaman = 1;
                        }
                    }
                }
            }
            // danh boss
            else if (event[i] == 99)
            {
                if (level == 10)
                {
                    if (event[i - 3] == 6 && shaman == 1)
                    {
                        HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                        shaman = 0;
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                {

                    rescue = 0;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }

            // siren
            else if (event[i] == 7)
            {
                if (shaman == 1 || siren == 1)
                {
                    if (event[i - 3] == 7 && siren == 1)
                    {
                        level = exlevel;
                        siren = 0;
                    }
                    if (event[i - 3] == 6 && shaman == 1)
                    {
                        HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                        shaman = 0;
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                {
                    int b = (i + 1) % 10;
                    int levelO;
                    levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
                    if (levelO == level)
                    {
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    if (level > levelO)
                    {
                        level = (level + 2 > 9) ? 10 : level + 2;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    if (level < levelO)
                    {
                        if (maidenkiss > 0)
                        {
                            maidenkiss--;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        }
                        else
                        {
                            exlevel = level;
                            level = 1;
                            siren = 1;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        }
                    }
                }
            }

            // gap merlin
            else if (event[i] == 18)
            {

                if (merlin == 1)
                {
                    if (event[i - 3] == 7 && siren == 1)
                    {
                        level = exlevel;
                        siren = 0;
                    }
                    if (event[i - 3] == 6 && shaman == 1)
                    {
                        HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                        shaman = 0;
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                {
                    ifstream file_merlin;
                    int n9;
                    file_merlin.open(file_merlin_pack.c_str());
                    file_merlin >> n9;
                    string item[n9];
                    file_merlin.ignore(1); // bỏ qua kí tự xuống dòng sau n9
                    for (int j = 0; j < n9; j++)
                    {
                        getline(file_merlin, item[j]);
                    }

                    file_merlin.close();
                    for (int h = 0; h < n9; h++)
                    {
                        string name = item[h];
                        bool isMerlinItem = (name.find("Merlin") != string::npos) || (name.find("merlin") != string::npos);
                        bool isValidItem = true;
                        for (size_t k = 0; k < name.size(); ++k)
                        {
                            char character = tolower(name[k]);
                            name[k] = character;
                        }

                        string merlinName = "merlin";
                        for (int j = 0; j < 6; j++)
                        {
                            if (name.find(merlinName[j]) == string::npos)
                            {
                                isValidItem = false;
                                break;
                            }
                        }

                        if (isValidItem && !isMerlinItem)
                        {
                            HP += 2;
                        }
                        else if (isMerlinItem)
                        {
                            HP += 3;
                        }

                        if (HP > maxHP)
                        {
                            HP = maxHP;
                        }
                    }
                    if (event[i - 3] == 7 && siren == 1)
                    {
                        level = exlevel;
                        siren = 0;
                    }
                    if (event[i - 3] == 6 && shaman == 1)
                    {
                        HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                        shaman = 0;
                    }
                    merlin = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }

            // gap aclepius
            else if (event[i] == 19)
            {

                if (asclepius == 1)
                {
                    if (event[i - 3] == 7 && siren == 1)
                    {
                        level = exlevel;
                        siren = 0;
                    }
                    if (event[i - 3] == 6 && shaman == 1)
                    {
                        HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                        shaman = 0;
                    }
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                {

                    ifstream file_asclepius;
                    int r1, c1;
                    file_asclepius.open(file_asclepius_pack.c_str());
                    file_asclepius >> r1 >> c1;
                    int potion[r1][c1];
                    file_asclepius.ignore(1);
                    for (int k = 0; k < r1; k++)
                    {
                        for (int j = 0; j < c1; j++)
                        {
                            file_asclepius >> potion[k][j];
                        }
                    }
                    file_asclepius.close();

                    for (int k = 0; k < r1; k++)
                    {
                        int thuoc = 0;
                        for (int j = 0; j < c1; j++)
                        {

                            if (potion[k][j] == 16)
                            {
                                remedy = (remedy + 1 > 99) ? 99 : remedy + 1;
                                thuoc++;
                            }
                            if (potion[k][j] == 17)
                            {
                                maidenkiss = (maidenkiss + 1 > 99) ? 99 : maidenkiss + 1;
                                thuoc++;
                            }
                            if (potion[k][j] == 18)
                            {
                                phoenixdown = (phoenixdown + 1 > 99) ? 99 : phoenixdown + 1;
                                thuoc++;
                            }
                            if (thuoc == 3)
                            {
                                thuoc == 0;
                                break;
                            }
                        }
                        thuoc = 0;
                    }
                    if (shaman == 1 && remedy > 0)
                    {
                        HP = HP * 5;
                        remedy--;
                        shaman = 0;
                    }
                    if (siren == 1 && maidenkiss > 0)
                    {
                        maidenkiss--;
                        level = exlevel;
                        siren = 0;
                    }
                    if (event[i - 3] == 7 && siren == 1 && maidenkiss == 0)
                    {
                        level = exlevel;
                        siren = 0;
                    }
                    if (event[i - 3] == 6 && shaman == 1 && remedy == 0)
                    {
                        HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                        shaman = 0;
                    }
                    asclepius = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }
            else
            {
                string nam = to_string(event[i]);

                ifstream file_mush;
                int n2;
                file_mush.open(file_mush_ghost.c_str());
                file_mush >> n2;
                int num[n2];

                // Đọc các số từ file vào mảng động
                for (int j = 0; j < n2; j++)
                {
                    file_mush.ignore(1); // bỏ qua kí tự phẩy
                    file_mush >> num[j];
                }

                // Đóng file
                file_mush.close();
                int numm[n2];
                for (int j = 0; j < n2; j++)
                {
                    numm[j] = num[j];
                }
                for (int j = 0; j < n2; j++)
                {
                    if (numm[j] < 0)
                    {
                        numm[j] = -numm[j];
                    }

                    numm[j] = (17 * numm[j] + 9) % 257;
                }
                for (int k = 2; k < nam.length(); k++)
                {

                    if (nam[k] == '1')
                    {
                        int maxi = 0, mini = 0;
                        for (int h = 1; h < n2; h++)
                        {

                            if (num[h] >= num[maxi])
                            {
                                maxi = h;
                            }
                            if (num[h] <= num[mini])
                            {
                                mini = h;
                            }
                        }
                        HP -= (maxi + mini);
                    }
                    if (nam[k] == '2')
                    {
                        int mtx = -2, mti = -3; // giá trị ban đầu của mtx và mti

                        // Tìm đỉnh núi trong mảng
                        for (int h = 1; h < n2 - 1; h++)
                        {
                            if (num[h] > num[h - 1] && num[h] > num[h + 1])
                            { // tìm đỉnh núi
                                mtx = num[h];
                                mti = h;
                                break;
                            }
                        }
                        if (mtx == -2 && num[0] > num[1])
                        { // kiểm tra đỉnh núi ở phần tử đầu tiên
                            mtx = num[0];
                            mti = 0;
                        }
                        if (mtx == -2 && num[n2 - 1] > num[n2 - 2])
                        { // kiểm tra đỉnh núi ở phần tử cuối cùng
                            mtx = num[n2 - 1];
                            mti = n2 - 1;
                        }

                        // Kiểm tra nếu không tìm thấy đỉnh núi thì cập nhật giá trị mtx và mti
                        if (mtx == -2 && mti == -3)
                        {
                            mtx = -2;
                            mti = -3;
                        }

                        // Kiểm tra xem dãy số có hình dạng núi hay không
                        bool is_nui = true;
                        int h = 0;
                        while (h < mti)
                        { // kiểm tra tính tăng dần
                            if (num[h] >= num[h + 1])
                            {
                                is_nui = false;
                                break;
                            }
                            h++;
                        }
                        while (h < n2 - 1)
                        { // kiểm tra tính giảm dần
                            if (num[h] <= num[h + 1])
                            {
                                is_nui = false;
                                break;
                            }
                            h++;
                        }
                        if (!is_nui)
                        { // nếu dãy số không có hình dạng núi
                            mtx = -2;
                            mti = -3;
                            HP -= (mtx + mti);
                        }
                        else
                        { // nếu dãy số có hình dạng núi
                            HP -= (mtx + mti);
                        }
                    }
                    if (nam[k] == '3')
                    {

                        int maxi2 = n2 - 1;
                        int mini2 = n2 - 1;
                        for (int h = n2 - 2; h >= 0; h--)
                        {
                            if (numm[h] >= numm[maxi2])
                            {
                                maxi2 = h;
                            }
                            if (numm[h] <= numm[mini2])
                            {
                                mini2 = h;
                            }
                        }
                        HP = HP - (maxi2 + mini2);
                    }
                    if (nam[k] == '4')
                    {

                        int max1 = numm[2], min1 = numm[2], max2_3x = -5, max2_3i = -7;
                        if (n2 == 1)
                        {
                            max2_3x = -5, max2_3i = -7;
                        }
                        else if (n2 == 2)
                        {
                            if (numm[0] == numm[1])
                            {
                                max2_3x = -5, max2_3i = -7;
                            }
                            else if (numm[0] > numm[1])
                            {
                                max2_3x = numm[1], max2_3i = 1;
                            }
                            else
                            {
                                max2_3x = numm[0], max2_3i = 0;
                            }
                        }
                        else if (n2 > 2)
                        {
                            int h;
                            if (numm[0] == numm[1] && numm[0] == numm[2])
                            {
                                max2_3x = -5, max2_3i = -7;
                            }
                            else if (numm[0] == numm[1] || numm[0] == numm[2] || numm[1] == numm[2])
                            {
                                for (h = 1; h >= 0; h--)
                                {
                                    if (numm[h] <= min1)
                                    {
                                        min1 = numm[h];
                                        max2_3x = min1;
                                        max2_3i = h;
                                    }
                                }
                            }
                            else
                            {
                                int max1;
                                if (numm[0] > numm[1])
                                {
                                    max1 = numm[0];
                                    max2_3x = numm[1];
                                }
                                else
                                {
                                    max1 = numm[1];
                                    max2_3x = numm[0];
                                }

                                for (int l = 2; l < 3; l++)
                                {
                                    if (numm[l] > max1)
                                    {
                                        max2_3x = max1;
                                        max1 = numm[l];
                                    }
                                    else if (numm[l] > max2_3x)
                                    {
                                        max2_3x = numm[l];
                                    }

                                    for (int t = 0; t < 3; t++)
                                    {
                                        if (numm[t] == max2_3x)
                                        {
                                            max2_3i = t;
                                        }
                                    }
                                }
                            }
                        }
                        HP -= (max2_3x + max2_3i);
                    }
                    if (HP > maxHP)
                    {
                        HP = maxHP;
                    }
                    if (HP <= 0 && phoenixdown <= 0)
                    {
                        break;
                    }
                    if (HP <= 0 && phoenixdown > 0)
                    {
                        HP = maxHP;
                        phoenixdown--;
                        if (shaman == 1)
                        {
                            shaman = 0;
                        }
                        if (siren == 1)
                        {

                            siren = 0;
                            level = exlevel;
                        }
                    }
                }
                if (HP <= 0)
                {

                    rescue = 0;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
                else
                {
                    if (event[i - 3] == 7 && siren == 1)
                    {
                        level = exlevel;
                        siren = 0;
                    }
                    if (event[i - 3] == 6 && shaman == 1)
                    {
                        HP = (HP * 5) > maxHP ? maxHP : HP * 5;
                        shaman = 0;
                    }
                }

                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
        }
    }
    else // vua arthur va lancelot
    {
        for (int i = 0; i < dem + 1; i++)
        {

            if (i == dem)
            {
                rescue = 1;
            }
            // ma 15 nhat remedy
            if (event[i] == 15)
            {

                if (remedy < 99 && remedy >= 0)
                {
                    remedy++;

                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // ma 16 nhat maidenkiss
            else if (event[i] == 16)
            {

                if (maidenkiss < 99 && maidenkiss >= 0)
                {
                    maidenkiss++;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // ma 17 nhat phoenixdown
            else if (event[i] == 17)
            {

                if (phoenixdown < 99 && phoenixdown >= 0)
                {
                    phoenixdown++;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // ma 12 HP ha den fibonaci gan nhat
            else if (event[i] == 12)
            {
                int a = 0, b = 1, c = 1;
                while (c < HP)
                {
                    a = b;
                    b = c;
                    c = a + b;
                }

                int Fib = b;
                if (HP > 1)
                {
                    HP = Fib;
                }
                else
                {
                    HP = 1;
                }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // ma 11 hp tang den so nguyen to gan nhat
            else if (event[i] == 11)
            {
                int n1 = ((level + phoenixdown) % 5 + 1) * 3;
                int s1 = n1 * ((2 * 99) + (n1 - 1) * (-2)) / 2;
                HP = HP + (s1 % 100);
                if (isPrime(HP))
                {
                    HP++;
                }
                else
                {
                    for (int j = HP + 1; j <= 999; j++)
                    {
                        if (isPrime(j))
                        {
                            HP = j;
                            break;
                        }
                    }
                }
                if (HP > maxHP)
                {
                    HP = maxHP;
                }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // ma 0 giai cuu
            else if (event[i] == 0)
            {

                rescue = 1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
            else if (event[i] > 0 && event[i] < 6) // danh quai
            {
                level = (level > 9) ? 10 : level + 1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // ma 6 va 7
            else if (event[i] == 6 || event[i] == 7)
            {

                level = (level + 2 > 9) ? 10 : level + 2;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // danh boss
            else if (event[i] == 99)
            {
                if (maxHP == 999 || (isPrime(maxHP) && level >= 8))
                {
                    level = 10;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                {

                    rescue = 0;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }

            // gap merlin
            else if (event[i] == 18)
            {

                if (merlin == 1)
                {

                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                {
                    ifstream file_merlin;
                    int n9;
                    file_merlin.open(file_merlin_pack.c_str());
                    file_merlin >> n9;
                    string item[n9];
                    file_merlin.ignore(1); // bỏ qua kí tự xuống dòng sau n9
                    for (int j = 0; j < n9; j++)
                    {
                        getline(file_merlin, item[j]);
                    }

                    file_merlin.close();
                    for (int j = 0; j < n9; j++)
                    {
                        string name = item[j];
                        bool isMerlinItem = (name.find("Merlin") != string::npos) || (name.find("merlin") != string::npos);
                        bool isValidItem = true;
                        for (size_t k = 0; k < name.size(); ++k)
                        {
                            char character = tolower(name[k]);
                            name[k] = character;
                        }

                        string merlinName = "merlin";
                        for (int k = 0; k < 6; k++)
                        {
                            if (name.find(merlinName[k]) == string::npos)
                            {
                                isValidItem = false;
                                break;
                            }
                        }

                        if (isValidItem && !isMerlinItem)
                        {
                            HP += 2;
                        }
                        else if (isMerlinItem)
                        {
                            HP += 3;
                        }

                        if (HP > maxHP)
                        {
                            HP = maxHP;
                        }
                    }

                    merlin = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }

            // gap aclepius
            else if (event[i] == 19)
            {
                if (asclepius == 1)
                {

                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else
                {

                    ifstream file_asclepius;
                    int r1, c1;
                    file_asclepius.open(file_asclepius_pack.c_str());
                    file_asclepius >> r1 >> c1;
                    int potion[r1][c1];
                    file_asclepius.ignore(1);
                    for (int k = 0; k < r1; k++)
                    {
                        for (int j = 0; j < c1; j++)
                        {
                            file_asclepius >> potion[k][j];
                        }
                    }
                    file_asclepius.close();

                    for (int k = 0; k < r1; k++)
                    {
                        int thuoc = 0;
                        for (int j = 0; j < c1; j++)
                        {

                            if (potion[k][j] == 16)
                            {
                                remedy = (remedy + 1 > 99) ? 99 : remedy + 1;
                                thuoc++;
                            }
                            if (potion[k][j] == 17)
                            {
                                maidenkiss = (maidenkiss + 1 > 99) ? 99 : maidenkiss + 1;
                                thuoc++;
                            }
                            if (potion[k][j] == 18)
                            {
                                phoenixdown = (phoenixdown + 1 > 99) ? 99 : phoenixdown + 1;
                                thuoc++;
                            }
                            if (thuoc == 3)
                            {
                                thuoc == 0;
                                break;
                            }
                        }
                        thuoc = 0;
                    }

                    asclepius = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }
            else
            {
                string nam = to_string(event[i]);

                ifstream file_mush;
                int n2;
                file_mush.open(file_mush_ghost.c_str());
                file_mush >> n2;
                int num[n2];

                // Đọc các số từ file vào mảng động
                for (int j = 0; j < n2; j++)
                {
                    file_mush.ignore(1); // bỏ qua kí tự phẩy
                    file_mush >> num[j];
                }

                // Đóng file
                file_mush.close();
                int numm[n2];
                for (int j = 0; j < n2; j++)
                {
                    numm[j] = num[j];
                }
                for (int j = 0; j < n2; j++)
                {
                    if (numm[j] < 0)
                    {
                        numm[j] = -numm[j];
                    }

                    numm[j] = (17 * numm[j] + 9) % 257;
                }
                for (int k = 2; k < nam.length(); k++)
                {

                    if (nam[k] == '1')
                    {
                        int maxi = 0, mini = 0;
                        for (int h = 1; h < n2; h++)
                        {

                            if (num[h] >= num[maxi])
                            {
                                maxi = h;
                            }
                            if (num[h] <= num[mini])
                            {
                                mini = h;
                            }
                        }
                        HP -= (maxi + mini);
                    }
                    if (nam[k] == '2')
                    {
                        int mtx = -2, mti = -3; // giá trị ban đầu của mtx và mti

                        // Tìm đỉnh núi trong mảng
                        for (int h = 1; h < n2 - 1; h++)
                        {
                            if (num[h] > num[h - 1] && num[h] > num[h + 1])
                            { // tìm đỉnh núi
                                mtx = num[h];
                                mti = h;
                                break;
                            }
                        }
                        if (mtx == -2 && num[0] > num[1])
                        { // kiểm tra đỉnh núi ở phần tử đầu tiên
                            mtx = num[0];
                            mti = 0;
                        }
                        if (mtx == -2 && num[n2 - 1] > num[n2 - 2])
                        { // kiểm tra đỉnh núi ở phần tử cuối cùng
                            mtx = num[n2 - 1];
                            mti = n2 - 1;
                        }

                        // Kiểm tra nếu không tìm thấy đỉnh núi thì cập nhật giá trị mtx và mti
                        if (mtx == -2 && mti == -3)
                        {
                            mtx = -2;
                            mti = -3;
                        }

                        // Kiểm tra xem dãy số có hình dạng núi hay không
                        bool is_nui = true;
                        int h = 0;
                        while (h < mti)
                        { // kiểm tra tính tăng dần
                            if (num[h] >= num[h + 1])
                            {
                                is_nui = false;
                                break;
                            }
                            h++;
                        }
                        while (h < n2 - 1)
                        { // kiểm tra tính giảm dần
                            if (num[h] <= num[h + 1])
                            {
                                is_nui = false;
                                break;
                            }
                            h++;
                        }
                        if (!is_nui)
                        { // nếu dãy số không có hình dạng núi
                            mtx = -2;
                            mti = -3;
                            HP -= (mtx + mti);
                        }
                        else
                        { // nếu dãy số có hình dạng núi
                            HP -= (mtx + mti);
                        }
                    }
                    if (nam[k] == '3')
                    {

                        int maxi2 = n2 - 1;
                        int mini2 = n2 - 1;
                        for (int h = n2 - 2; h >= 0; h--)
                        {
                            if (numm[h] >= numm[maxi2])
                            {
                                maxi2 = h;
                            }
                            if (numm[h] <= numm[mini2])
                            {
                                mini2 = h;
                            }
                        }
                        HP = HP - (maxi2 + mini2);
                    }
                    if (nam[k] == '4')
                    {

                        int max1 = numm[2], min1 = numm[2], max2_3x = -5, max2_3i = -7;
                        if (n2 == 1)
                        {
                            max2_3x = -5, max2_3i = -7;
                        }
                        else if (n2 == 2)
                        {
                            if (numm[0] == numm[1])
                            {
                                max2_3x = -5, max2_3i = -7;
                            }
                            else if (numm[0] > numm[1])
                            {
                                max2_3x = numm[1], max2_3i = 1;
                            }
                            else
                            {
                                max2_3x = numm[0], max2_3i = 0;
                            }
                        }
                        else if (n2 > 2)
                        {
                            int h;
                            if (numm[0] == numm[1] && numm[0] == numm[2])
                            {
                                max2_3x = -5, max2_3i = -7;
                            }
                            else if (numm[0] == numm[1] || numm[0] == numm[2] || numm[1] == numm[2])
                            {
                                for (h = 1; h >= 0; h--)
                                {
                                    if (numm[h] <= min1)
                                    {
                                        min1 = numm[h];
                                        max2_3x = min1;
                                        max2_3i = h;
                                    }
                                }
                            }
                            else
                            {
                                int max1;
                                if (numm[0] > numm[1])
                                {
                                    max1 = numm[0];
                                    max2_3x = numm[1];
                                }
                                else
                                {
                                    max1 = numm[1];
                                    max2_3x = numm[0];
                                }

                                for (int l = 2; l < 3; l++)
                                {
                                    if (numm[l] > max1)
                                    {
                                        max2_3x = max1;
                                        max1 = numm[l];
                                    }
                                    else if (numm[l] > max2_3x)
                                    {
                                        max2_3x = numm[l];
                                    }

                                    for (int t = 0; t < 3; t++)
                                    {
                                        if (numm[t] == max2_3x)
                                        {
                                            max2_3i = t;
                                        }
                                    }
                                }
                            }
                        }
                        HP -= (max2_3x + max2_3i);
                    }
                    if (HP > maxHP)
                    {
                        HP = maxHP;
                    }
                    if (HP <= 0 && phoenixdown <= 0)
                    {
                        break;
                    }
                    if (HP <= 0 && phoenixdown > 0)
                    {
                        HP = maxHP;
                        phoenixdown--;
                    }
                }
                if (HP <= 0)
                {
                    rescue = 0;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
        }
    }
}