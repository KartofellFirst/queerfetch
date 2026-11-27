<h1><p align=center>queerfetch</p></h1>

Fast and only fetch you may need for your Mac/Linux-based system. <br>
Despite usual info, `queerfetch` provides you with such outputs as: <br>
1. Gayness level (0 to 100 scale of how gay you are based on your system info)
2. Attachment style (One of eight attachment styles)
3. Attachment security (In case you don’t understand attachment style classifications, there is a scale)
4. Bottom license/Top license (Queerfetch grants you with a bottom or top license)
5. Bottom License points (How bottom are you at the scale from 0 to 100?)


source code is in /src/fetch.gay -> [visit](/src/fetch.gay) <br>
Language standard: C23

<h3><p align=center>setup</p></h3>

install:

```bash
make megay
```

build:

```bash
make gay
```

<sup>_or `make clean gay` for clean build_</sup>

uninstall:

```bash
make uninstall
```

<h3><p align=center>configuration</p></h3>

_fallback config -> [see](/config/config.queer)_ <br>
your custom config must be available at `~/.config/queerfetch/config.queer` <br>


| Variable | Output |
|---|---|
| `OSNAME` | OS name |
| `KERNEL_VERSION` | kernel release |
| `SHELL` | shell name |
| `USERNAME` | current user |
| `TIMEZONE` | UTC offset, e.g. `+0300` |
| `HOURS`, `MINUTES`, `SECONDS` | local time |
| `UPTIME_H`, `UPTIME_M` | uptime in hours and minutes |
| `RAM`, `RAM_USED` | total and used RAM in MiB |
| `STORAGE` | size of the root filesystem in MiB |
| `GAYNESS` | gayness level, 0 to 100 |
| `ATTACHMENT_STYLE` | attachment style |
| `ATTACHMENT_SECURITY` | attachment security, 0 to 100 |
| `LICENSE` | `Top` or `Bottom` |
| `BOTTOM_LICENSE_POINTS` | license points, 0 to 100 |
| `VOLUME` | your speakers volume, 0 to 100 |
| `BATTERY_STATUS` | charging / discharging |
| `BATTERY_PERCENTAGE` | 0% to 100% |

to use them, in your config wrap variable name in `%{}%`

```
OS: %{OSNAME}% %{KERNEL_VERSION}%
TIME: %{HOURS}%:%{MINUTES}%:%{SECONDS}%
```

### math

Numeric variables support `+`, `-`, `*`, `/` and parentheses. Fractional results are shown with two decimals.

```
RAM: %{RAM_USED/1024}% / %{RAM/1024}% GiB
```

### repeat

`%{count * text}%` prints `text` `count` times, which is handy for progress bars:

```
[%{(GAYNESS/10) * █}%%{(10 - GAYNESS/10) * ░}%]
```

With `GAYNESS` at 30 this gives `[███░░░░░░░]`.

- `count` can be any math expression. It is rounded to the nearest integer (exact halves go to the even number) and capped at 1000. Zero or negative values print nothing.
- Spaces around `text` are trimmed. Use quotes to keep them: `%{3 * "~ "}%`
- Quote numbers too: `%{5 * 2}%` prints `10`, while `%{5 * "2"}%` prints `22222`.


### colors and styles

`RESET`, `BOLD`, `DIM`, `ITALIC`, `UNDERLINE`, <br>
`BLACK`, `RED`, `GREEN`, `YELLOW`, `BLUE`, `MAGENTA`, <br>
`CYAN`, `WHITE`, or any `#rrggbb` color (needs a truecolor terminal).

```
%{BOLD}%%{#ff69b4}%USER:%{RESET}% %{USERNAME}%
```

A style stays active until `%{RESET}%`; colors are also replaced by the next color.

<h3><p align=center>usage</p></h3>

after the installation, run

```bash
queerfetch
```

<h3><p align=center>footer</p></h3>

Project is licensed under the [MIT License](LICENSE) <br>

Authors will be listed in [NOTICE](NOTICE) <br>

2026
