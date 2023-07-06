from manimlib import *
import numpy as np

class CSE(Scene):
    def construct(self):
        axes = Axes(
            
            x_range=(-10, 10),
            
            y_range=(-3, 10),
            
            height=6,
            width=10,
            
            axis_config={
                "stroke_color": GREY_A,
                "stroke_width": 2,
            },
            
            y_axis_config={
                "include_tip": False,
            }
        )
        
        axes.add_coordinate_labels(
            font_size=12,
            num_decimal_places=1,
        )
        self.add(axes)
        
        direct_line = axes.get_graph(lambda x: -2)
        direct_line.set_stroke(BLUE)

        parabola = axes.get_graph(lambda x: x**2 / 8)
        parabola.set_stroke(BLUE)
        self.play(
            ShowCreation(parabola)
        )
        self.play(
            ShowCreation(direct_line)
        )

        dot3 = Dot(color=RED)  #焦點
        dot3.move_to(axes.c2p(0, 2))
        self.play(FadeIn(dot3, scale=0.5))

        dot = Dot(color=RED) #P
        dot.move_to(axes.i2gp(2, parabola))
        self.play(FadeIn(dot, scale=0.5))

        dot2 = Dot(color=RED) #L上一點
        dot2.move_to(axes.i2gp(2, direct_line))
        self.play(FadeIn(dot2, scale=0.5))

        

        line = Line(dot.get_center(), dot2.get_center(), color=RED)
        line2 = Line(dot.get_center(), dot3.get_center(), color=RED)

        number = DecimalNumber(10, 
                show_ellipsis=True,
                num_decimal_places=2,
                include_sign=False,
                font_size = 18,
                )
        
        number2 = DecimalNumber(10, 
                show_ellipsis=True,
                num_decimal_places=2,
                include_sign=False,
                font_size = 18,
            )
        
        # def update_line(line):
        #     new_line = Line(dot.get_center(), dot2.get_center(), color=GREEN)
            
        #     line.become(new_line)

        # def update_line2(line2):
        #     new_line2 = Line(dot.get_center(), dot3.get_center(), color=GREEN)
        #     line2.become(new_line2) 

        
        x_tracker = ValueTracker(2)
        f_always(
            dot.move_to,
            lambda: axes.i2gp(x_tracker.get_value(), parabola)
        )
        f_always(
            dot2.move_to,
            lambda: axes.i2gp(x_tracker.get_value(), direct_line)
        )
        

        always_redraw(lambda: line.become(Line(dot.get_center(), dot2.get_center(), color=RED)))
        always_redraw(lambda: line2.become(Line(dot.get_center(), dot3.get_center(), color=RED)))

        self.play(ShowCreation(line))
        self.play(ShowCreation(line2))

        always(number.next_to, line)
        always_redraw(lambda: number.set_value(line.get_length() * 4 / 1.85))
        always(number2.next_to, dot3)
        always_redraw(lambda: number2.set_value(line.get_length() * 4 / 1.85))

        
        self.add(number)
        self.add(number2)

        # self.play(UpdateFromFunc(line, update_line),UpdateFromFunc(line2, update_line2),
        #     x_tracker.animate.set_value(7), run_time=4)
        # self.wait(2)

        # self.play(UpdateFromFunc(line, update_line),UpdateFromFunc(line2, update_line2),
        #     x_tracker.animate.set_value(-2), run_time=6)
        # self.wait(2)

        

        self.play(
            x_tracker.animate.set_value(5), run_time=2)
        self.wait(2)

        self.play(
            x_tracker.animate.set_value(-4), run_time=2)
        self.wait(2)

        self.play(
            x_tracker.animate.set_value(0), run_time=2)
        self.wait(2)

        

#manimgl test.py CSE