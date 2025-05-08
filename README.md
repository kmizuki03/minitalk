# minitalk

UNIXのシグナル（SIGUSR1, SIGUSR2）を使って、プロセス間通信を行う小規模な通信プログラムを作成します。

## ✅ 構成

- `server`：起動時に PID を表示、メッセージを受信・出力
- `client`：引数としてPIDと文字列を受け取り、1文字ずつ送信

## 🔧 使用可能関数

- `write`
- `malloc`
- `free`
- `exit`
- `kill`
- `getpid`
- `signal`
- `sigaction`
- `sigemptyset`
- `sigaddset`
- `pause`
- `usleep`
- `sleep`
- `ft_printf（自作）`

## 💎 ボーナス（任意）

- メッセージ受信確認（ACK）をクライアントに返す
- Unicode対応
