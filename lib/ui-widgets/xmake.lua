target("lcui-ui-widgets")
    set_kind("shared")
    add_files("src/**.c")
    add_deps("lcui-util", "lcui-ui")
