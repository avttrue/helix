Когда было мне лет 8 или около того, попался ко мне в руки журнальчик типа «Науки и Жизни» или что-то подобное. И была в том журнале статья про математические забавы. В частности - предлагалось на бумаге в клеточку пронумеровать клетки по спирали от центра и закрасить все простые (у которых нет делителей кроме 1 и самого себя) числа. Какие делались выводы из этого мероприятия я уж и не помню.
В майские праздники было немного времени и, тут я вспомнил! Не прошло и сорока лет.

Короче, говоря - вот вам программка. Что она делает. Заполнить матрицу по спирали из центра можно восемью способами. Каждый такой способ реализован в коде. Принцип именования каждой матрицы такой: имеем матрицу TL - из центра пошли наверх (top), потом налево (left) и т.д. Берём одну спираль - заполняем, отмечаем на ней простые числа. Потом - следующую спираль и т.д. Потом все матрицы с отмеченными простыми числами совмещаем.
Что получится? Смотрите. Размер матрицы выбирайте таким, чтобы не происходил перенос строк. На моём экране это 171.
Проект сделан в QTCreator'е, программа тестировалась под Linux. Теоретически, собирать можно в чём угодно и запускать результат тоже. Это чистый C++. Ну и не судите строго, я ж не настоящий программист.

https://github.com/avttrue/helix
