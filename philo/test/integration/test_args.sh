#!/bin/bash

# テスト結果をカウント
pass=0
fail=0

run_test() {
    description=$1
    shift
    expected=$1
    shift
    output=$(./philo "$@" 2>&1)
    status=$?
    if [ $status -eq $expected ]; then
        echo "✅ PASS: $description"
        pass=$((pass+1))
    else
        echo "❌ FAIL: $description (exit=$status, expected=$expected)"
        echo "    output: $output"
        fail=$((fail+1))
    fi
}

# ---- テストケース ----
run_test "正常引数" 0 5 800 200 200
run_test "引数不足" 1 5 800 200
run_test "引数に文字列" 1 5 abc 200 200
run_test "負数引数" 1 -5 800 200 200
run_test "ゼロ引数" 1 0 800 200 200
run_test "回数指定あり" 0 5 800 200 200 3

# 結果まとめ
echo ""
echo "Tests passed: $pass"
echo "Tests failed: $fail"
