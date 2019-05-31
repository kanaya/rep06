require 'optparse'

params = ARGV.getopts('', 'separator:', 'input:')

found = false
File.open(params['input'], 'r') do |f|
	f.each_line do |ln|
		if not found then
			n = ln.index(params['separator'])
			if n != nil then
				puts(ln.slice(n, ln.length - n))
				found = true
			end
		else
			puts(ln)
		end
	end
	puts('Not found.') if not found
end
