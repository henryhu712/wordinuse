(function($) {

  var words = [];
  var current_word_index = 0;
  var current_pos = -1;
  var wordInfo = {
    'word': '',
    'translation': '',
    'pos': []
  };

  // Display a new word
  function init_show_word() {
    wordInfo.word = words[current_word_index]['word'];
    wordInfo.translation = words[current_word_index]['tr'];

    var theWord = wordInfo.word;
    var ix = 0;
    var pos = Math.floor((Math.random() * theWord.length));
    var html = '';
    var isFirstEmpty = false;
    for (ix=0; ix<theWord.length; ++ix) {
      html += '<span class="letter' + (!isFirstEmpty && pos!=ix ? ' blink' : '') + ' data-letter="">';
      html += pos == ix ? theWord[ix] : '_';
      html += ' </span>';
      console.log(ix);
      if (!isFirstEmpty && pos != ix) {
        isFirstEmpty = true;
        current_pos = ix;
      }
    }

    $('.word-line-wrap').empty().append(html);
    $('.translation-line-wrap').empty().append(wordInfo.translation);
    $('.answer-line-wrap').empty();

  }

  // Check user input
  function check_input() {
    var answer = $('.answer-line-wrap');
    answer.empty().append( wordInfo.word );
  }

  // Back
  function back_delete() {
          var blinking_word = $('.word-line-wrap span').eq(current_pos);
          blinking_word.removeClass('blink');
          current_pos--;
          var pre_blinking_word = $('.word-line-wrap span').eq(current_pos);
          pre_blinking_word.addClass('blink').empty().append(' _');
  }

  // Go next
  function next_word() {
    current_word_index++;
    init_show_word();
    $('.number-of-word').empty().append( current_word_index + 1 );
  }


  Drupal.behaviors.muread_home = {
    attach: function(context, settings) {

      words = settings.word_info.words;

      init_show_word();


      $('.keyboard-wrap .letter').on('click', function(e) {
        var clickedLetter = $(this).data('letter');
        var blinking_word = $('.word-line-wrap span').eq(current_pos);
        blinking_word.empty().append(' ' + clickedLetter);
        blinking_word.removeClass('blink');

        if (current_pos >= wordInfo.word.length - 1) {
            check_input();
        }
        else {
            current_pos++;
            $('.word-line-wrap span').eq(current_pos).addClass('blink');
        }

      });

      $(document).keydown(function(ev) {
        if (ev.which == 8) {
          back_delete();
        }
      });

      $(document).keypress(function(ev) {
        var clickedChar = String.fromCharCode(ev.which);
        if (clickedChar === ' ') {
          var text = new SpeechSynthesisUtterance(wordInfo.word);
          window.speechSynthesis.speak(text);
        }
        
        clickedChar = clickedChar.toLowerCase();
        if (clickedChar.match(/[a-z]/)) {
          var blinking_word = $('.word-line-wrap span').eq(current_pos);
          blinking_word.empty().append(' ' + clickedChar);
          blinking_word.removeClass('blink');

          if (current_pos >= wordInfo.word.length - 1) {
            check_input();
          }
          else {
            current_pos++;
            $('.word-line-wrap span').eq(current_pos).addClass('blink');
          }
        }

        if (ev.which == 13) {
          next_word();
        }
      });

      $('.delete').on('click', function(e) {
        back_delete();
      });

      $('.next-word').on('click', function(e) {
        next_word();
      });

      $('.speak').on('click', function(e) {
        var text = new SpeechSynthesisUtterance(wordInfo.word);
        window.speechSynthesis.speak(text);
      });

      // Record hits
    /*
      $('.goto_origin').on('click', function() {
        var nid = $(this).data('nid');
        $.post('hit', {nid:nid}, function(result) {
        });
      });
      */

    }
  };

})(jQuery);
