W = 800
H = 300

class Kalman < Processing::App

  def setup
    @data = `Kalman/build/Debug/Kalman < data.txt`.split("\n").map {|e| e.split.map{|e| e.to_i}}
    # @data[i][0] - normal
    # @data[i][1] - kalman

    @i = 0
    background 100
    smooth
    color_mode RGB
    frame_rate 50
    fill 74
    no_stroke
    rect 10, H+20, W, 40
    
    fill 226, 37, 0
    rect 20, H+30, 20, 20
    
    fill 255
    rect 320, H+30, 20, 20
    
    
    fill 74
  end

  def draw
    return if @i >= @data.size

    no_stroke
    rect 10, 10, W, H

    y = H+10

    ([0, @i-W+3].max..@i).each_with_index do |i, x|
      x += 11

      # normalne
      stroke_weight 1
      stroke 226, 37, 0
      line x, y, x, y - @data[i][0]
      
      stroke_weight 2
      stroke 0
      point x, y - @data[i][0]
      
      #kalman
      stroke 255
      point x, y - @data[i][1]
    end
    @i += 1

  end

end

Kalman.new :title => "Kalman", :width => W + 20, :height => H + 70