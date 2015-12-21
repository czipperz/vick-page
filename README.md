# vick-page [![Build Status](https://travis-ci.org/czipperz/vick-page.svg?branch=master)](https://travis-ci.org/czipperz/vick-page)

Allows for movement on the buffer relative to the page
(`contents::y_offset` and `contents::max_y`).

Defines all functions in the `namespace page`.

| name                          | default binding |
|-------------------------------|-----------------|
| `page::move_to_window_top`    | `zt`            |
| `page::move_to_window_middle` | `zm`            |
| `page::move_to_window_bottom` | `zb`            |
| `page::move_to_window_top`    | `zT`            |
| `page::move_to_window_middle` | `zM`            |
| `page::move_to_window_bottom` | `zB`            |
| `page::move_up_page`          | `^B`            |
| `page::move_down_page`        | `^F`            |
| `page::move_up_half_page`     | `^U`            |
| `page::move_down_half_page`   | `^D`            |
