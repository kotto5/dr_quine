#!/bin/bash

echo "----------- Test Colleen --------------"
cd Colleen
echo "1. 実行ファイルの標準出力への出力内容が、自身のソースコードと一致しているか"
./Colleen > output.txt
diff output.txt Colleen.c
if [ $? -eq 0 ]; then
    echo "✅ Output matches the source code."
else
    echo "❌ Output does not match the source code."
fi
echo "🔸2. main 関数がある"
echo "🔸3. main 関数の中に comment out がある"
echo "🔸4. main 関数の外に comment out がある"

cd ..

echo "----------- Test Grace ----------"
cd Grace
echo "1. 実行ファイルは Grace_kid.c という名前のソースコードを生成する。その内容がソースコードと一致しているか"
./Grace
diff Grace_kid.c Grace.c
if [ $? -eq 0 ]; then
    echo "✅ Generated source code matches the original."
else
    echo "❌ Generated source code does not match the original."
fi

echo "2. マクロを4つ以以上利用していない"
cat Grace.c | grep -c "#define" | grep -qE '^[0-4]$'
if [ $? -eq 0 ]; then
    echo "✅ Macro usage is within the limit."
else
    echo "❌ Macro usage exceeds the limit."
fi

echo "🔸: 3. main 関数が定義されていない (マクロによって定義されている)"
echo "🔸: 4. comment out が1つ以上ある"


cd ..
echo "----------- Sully Test ----------"

cd Sully
echo "1. 実行ファイルは Sully_x.c (0 <= x <= 5) という名前のソースコードを生成する。その内容がソースコードと一致しているか"
./Sully
for i in {0..5}; do
    echo $PWD
    if [ -f "Sully_$i.c" ]; then
        diff "Sully_$i.c" Sully.c
        if [ $? -eq 0 ]; then
            echo "✅ Generated Sully_$i.c matches the original."
        else
            echo "❌ Generated Sully_$i.c does not match the original."
        fi
    else
        echo "❌ Sully_$i.c does not exist."
    fi
done
echo "🔸2. argc, argv を利用していない"


